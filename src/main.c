#include <stdio.h>

#include "snapshot.h"
#include "archdep.h"
#include "c64-snapshot.h"

int create1()
{
    printf("Hello World!\n");

    snapshot_t *snapshot = snapshot_create("/tmp.vsf", 1, 0, MACHINE_NAME);
    snapshot_close(snapshot);
    snapshot_display_error();

    snapshot_set_error(0);

    EM_ASM({
        // FIXME: Module.FS.readFile
        const content1 = Module.FS_readFile("/tmp.vsf");
        console.log("File content1:", content1);
    });

    // emscripten_run_script("Module.finish_main();");

    return 0;
}

int read1()
{
    printf("Hello World!1\n");

    EM_ASM({
        console.log("READ1", process.cwd());
        const data = fs.readFileSync('assets/vice-snapshot-20241025205910.vsf');
        const uint8Data = new Uint8Array(data);

        // FS.writeFile not FS_writeFile !
        const f = Module.FS.writeFile("/tmp.vsf", data);
    });

    printf("READ2\n");
    uint8_t major, minor;
    snapshot_t *snapshot = snapshot_open("/tmp.vsf", &major, &minor, MACHINE_NAME);
    snapshot_display_error();
    uint8_t m_major, m_minor;
    snapshot_module_t *m = snapshot_module_open(snapshot, "MAINCPU", &m_major, &m_minor);
    snapshot_display_error();
    CLOCK maincpu_clk;
    int res = SMR_CLOCK(m, &maincpu_clk);
    printf("RES=%d\n", res);

    snapshot_module_close(m);
    snapshot_display_error();

    snapshot_close(snapshot);
    snapshot_display_error();

    snapshot_set_error(0);

    EM_ASM({
        console.log("READ3");
        const content1 = Module.FS.readFile("/tmp.vsf");
        console.log("File content1:", content1);
    });

    // emscripten_run_script("Module.finish_main();");

    return 0;
}

/*
EMSCRIPTEN_KEEPALIVE
int safe_c64_snapshot_read(const char *filename, int flag)
{
    // Run the FS operation within an EM_ASM block with try-catch
    int result = EM_ASM_INT({
        try {
            const data = c64_snapshot_read("/tmp.vsf", 0);
            return 0;
        } catch (e) {
            return -1;
        } }, filename);

    return result;
}
*/

int read2()
{
    printf("Hello World!1\n");

    EM_ASM({
        console.log("READ1", process.cwd());
        const data = fs.readFileSync('assets/vice-snapshot-20241025205910.vsf');
        const uint8Data = new Uint8Array(data);

        // FS.writeFile not FS_writeFile !
        const f = Module.FS.writeFile("/tmp.vsf", data);
    });

    printf("READ2\n");
    app_init();
    int res = c64_snapshot_read("/tmp.vsf", 0);
    snapshot_display_error();
    printf("RES=%d\n", res);

    snapshot_display_error();

    snapshot_set_error(0);

    EM_ASM({
        console.log("READ3");
        const content1 = Module.FS.readFile("/tmp.vsf");
        console.log("File content1:", content1);
    });

    // emscripten_run_script("Module.finish_main();");

    return 0;
}

int main()
{
    read2();
}

#ifndef ARCHDEP_H
#define ARCHDEP_H

#include <emscripten/emscripten.h>
#include <stdarg.h>

#include "debug.h"

void app_init();

// snapshot.c

#define archdep_vice_exit emscripten_force_exit
#define archdep_remove remove
#define lib_free free
#define lib_malloc malloc
#define lib_realloc realloc
#define zfile_fopen fopen
#define zfile_fclose fclose
#define vsync_suspend_speed_eval(...) (0)
#define ui_error printf

#define PRI_SIZE_T "zu"

#define MODE_WRITE "wb"
#define MODE_WRITE_TEXT "wb"

#define MODE_READ "rb"
// #define MODE_READ_TEXT "rb"

// FIXME: Support "C64" too
#define MACHINE_NAME "C64SC"

#define VERSION_RC_NUMBER "0000"

// c64-snapshot.c

#include "c64.h"

const char *machine_get_name(void);

extern machine_context_t machine_context;

#define sound_snapshot_prepare(...) (0)
#define drive_cpu_execute_all(...) (0)
// #define maincpu_snapshot_write_module(...) (0)
#define c64_snapshot_write_module(...) (0)
#define ciacore_snapshot_write_module(...) (0)
#define ciacore_snapshot_write_module(...) (0)
#define sid_snapshot_write_module(...) (0)
#define drive_snapshot_write_module(...) (0)
#define fsdrive_snapshot_write_module(...) (0)
#define vicii_snapshot_write_module(...) (0)
#define c64_glue_snapshot_write_module(...) (0)
#define event_snapshot_write_module(...) (0)
#define memhacks_snapshot_write_modules(...) (0)
#define tapeport_snapshot_write_module(...) (0)
#define keyboard_snapshot_write_module(...) (0)
#define joyport_snapshot_write_module(...) (0)
#define joyport_snapshot_write_module(...) (0)
#define userport_snapshot_write_module(...) (0)

// #define maincpu_snapshot_read_module(...) (0)
#define vicii_snapshot_prepare(...) (0)
#define joyport_clear_devices(...) (0)
#define c64_snapshot_read_module(...) (0)
#define ciacore_snapshot_read_module(...) (0)
#define ciacore_snapshot_read_module(...) (0)
#define sid_snapshot_read_module(...) (0)
#define drive_snapshot_read_module(...) (0)
#define fsdrive_snapshot_read_module(...) (0)
#define vicii_snapshot_read_module(...) (0)
#define c64_glue_snapshot_read_module(...) (0)
#define event_snapshot_read_module(...) (0)
#define memhacks_snapshot_read_modules(...) (0)
#define tapeport_snapshot_read_module(...) (0)
#define keyboard_snapshot_read_module(...) (0)
#define joyport_snapshot_read_module(...) (0)
#define joyport_snapshot_read_module(...) (0)
#define userport_snapshot_read_module(...) (0)
#define sound_snapshot_finish(...) (0)
#define machine_trigger_reset(...) (0)

#define MACHINE_RESET_MODE_RESET_CPU (0)

// maincpu.h

#include "maincpu.h"

/*
#define machine_get_line_cycle (0)
#define mem_bank_list (0)
#define mem_bank_list_nos (0)

#define mem_bank_from_name (0)
#define mem_bank_index_from_bank (0)
#define mem_bank_flags_from_bank (0)

#define mem_bank_read (0)
#define mem_bank_peek (0)
#define mem_peek_with_config (0)
#define mem_bank_write (0)
#define mem_bank_poke (0)

#define mem_ioreg_list_get (0)

#define mem_toggle_watchpoints (0)
*/

#endif

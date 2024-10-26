#include <stdio.h>
#include <stdarg.h>

#include "archdep.h"
#include "log.h"
#include "interrupt.h"

int log_warning(log_t log, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    printf("Warning: ");
    vprintf(format, args);
    printf("\n");
    va_end(args);
    return 0;
}

int log_error(log_t log, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    printf("Error: ");
    vprintf(format, args);
    printf("\n");
    va_end(args);
    return 0;
}

machine_context_t machine_context;

const char *machine_get_name(void)
{
    return MACHINE_NAME;
}

void app_init()
{
    maincpu_int_status = interrupt_cpu_status_new();
}


#ifndef ARCHDEP_H
#define ARCHDEP_H

#include <emscripten/emscripten.h>
#include <stdarg.h>

#define archdep_vice_exit emscripten_force_exit
#define archdep_remove remove
#define lib_free free
#define lib_malloc malloc
#define zfile_fopen fopen
#define zfile_fclose fclose
#define vsync_suspend_speed_eval() /* vsync_suspend_speed_eval() */
#define ui_error printf

#define PRI_SIZE_T "zu"

#define MODE_WRITE "wb"
#define MODE_WRITE_TEXT "wb"

#define MODE_READ "rb"
// #define MODE_READ_TEXT "rb"

#define LOG_DEFAULT 0

// FIXME: Support "C64" too
#define MACHINE_NAME "C64SC"

#define VERSION_RC_NUMBER "0000"

void log_warning(int log_type, const char *format, ...);

#define log_error log_warning

#endif

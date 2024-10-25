#include <stdio.h>
#include <stdarg.h>

void log_warning(int log_type, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Print "Error: " prefix and the formatted message
    printf("Error: ");
    vprintf(format, args);
    printf("\n"); // Add newline at the end for clarity

    va_end(args);
}
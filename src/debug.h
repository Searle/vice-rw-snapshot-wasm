
#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>

#define lib_realloc realloc
#define lib_calloc calloc
#define lib_free free
#define lib_strdup strdup

// monitor.h

extern const char **(*mem_bank_list)(void);
extern const int *(*mem_bank_list_nos)(void);
extern int (*mem_bank_from_name)(const char *name);
extern int (*mem_bank_index_from_bank)(int bank);
extern int (*mem_bank_flags_from_bank)(int bank);
extern uint8_t (*mem_bank_read)(int bank, uint16_t addr, void *context);
extern uint8_t (*mem_bank_peek)(int bank, uint16_t addr, void *context);
extern uint8_t (*mem_peek_with_config)(int config, uint16_t addr, void *context);
extern void (*mem_bank_write)(int bank, uint16_t addr, uint8_t byte, void *context);
extern void (*mem_bank_poke)(int bank, uint16_t addr, uint8_t byte, void *context);
extern void (*mem_toggle_watchpoints)(int value, void *context);
extern void (*machine_get_line_cycle)(unsigned int *line, unsigned int *cycle, int *half_cycle);

extern struct mem_ioreg_list_s *(*mem_ioreg_list_get)(void *context);

// #define interrupt_cpu_status_new(...) (0)
// #define interrupt_cpu_status_init(...) (0)
// #define interrupt_cpu_status_destroy(...) (0)

#define LOG_DEFAULT (0)

typedef signed int log_t;

#define log_open(...) (0)

int log_out(log_t log, unsigned int level, const char *format, ...);

int log_debug(log_t log, const char *format, ...);
int log_verbose(log_t log, const char *format, ...);
int log_message(log_t log, const char *format, ...);
int log_warning(log_t log, const char *format, ...);
int log_error(log_t log, const char *format, ...);
int log_fatal(log_t log, const char *format, ...);

/* simple way to print to the default log, at debug level */
int log_printf(const char *format, ...);

#define machine_reset(...) (0)
#define mem_mmu_translate(...) (0)
#define autostart_advance(...) (0)
#define OPINFO_DELAYS_INTERRUPT(...) (0)
#define OPINFO_ENABLES_IRQ(...) (0)

// extern interrupt_cpu_status_t *maincpu_int_status;

#endif
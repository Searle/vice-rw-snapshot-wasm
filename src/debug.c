
#include "interrupt.h"

const char **(*mem_bank_list)(void) = NULL;

const int *(*mem_bank_list_nos)(void) = NULL;

int (*mem_bank_from_name)(const char *name) = NULL;
int (*mem_bank_index_from_bank)(int bank) = NULL;
int (*mem_bank_flags_from_bank)(int bank) = NULL;
uint8_t (*mem_bank_read)(int bank, uint16_t addr, void *context) = NULL;
uint8_t (*mem_bank_peek)(int bank, uint16_t addr, void *context) = NULL;
uint8_t (*mem_peek_with_config)(int config, uint16_t addr, void *context) = NULL;
void (*mem_bank_write)(int bank, uint16_t addr, uint8_t byte, void *context) = NULL;
void (*mem_bank_poke)(int bank, uint16_t addr, uint8_t byte, void *context) = NULL;
void (*mem_toggle_watchpoints)(int value, void *context) = NULL;
void (*machine_get_line_cycle)(unsigned int *line, unsigned int *cycle, int *half_cycle);

struct mem_ioreg_list_s *(*mem_ioreg_list_get)(void *context) = NULL;

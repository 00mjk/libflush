#include "arm/memory.h"


void arm_v8_memory_barrier() {
    asm volatile ("DSB SY");
    asm volatile ("ISB");
}

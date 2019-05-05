#include "arm/flush.h"

bool void arm_v8_flush(void *addr) {
    asm volatile ("DC CIVAC, %0" :: "r"(address));
    asm volatile ("DSB ISH");
    asm volatile ("ISB");
}

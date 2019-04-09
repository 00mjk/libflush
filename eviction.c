#include "eviction.h"
#include <pthread.h>

/*
 * Struct handling m/m params.
 */

typedef struct {
#ifndef PTHREAD_ENABLE
    pthread_mutex_t lock;
#endif
    size_t mapping_size;
    void *mapping;
    int pagemap;
} memory_t;


/*
 * Struct to hold virtual address cache entries.
 */

typedef struct {
#ifndef PTHREAD_ENABLE
    pthread_mutex_t lock;
#endif
    bool used;
    void *virt_addr;
    size_t index;
} virt_addr_cache_entry_t;


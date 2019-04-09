#include <sys/stat.h>
#include <fcntl.h>

#include "internal.h"
#include "libflush.h"
#include "stdlib.h"


/*
 * Init libflush session
 */

bool libflush_init(struct libflush_session_t **session, struct libflush_session_args_t *args) {  
    if (session == NULL) {
        return false;
    } 
    if ((*session = calloc(1, sizeof(struct libflush_session_t))) == NULL) {
        return false;
    }
    if (args) {
        (*session)->performance_register_div64 = args->performance_register_div64;
    }
#if HAVE_PAGEMAP_ACCESS == 1
    (*session)->memory.pagemap = open("/proc/self/pagemap", O_RDONLY);
    if ((*session)->memory.pagemap == -1) {
        free(*session);
        return false;
    }
#endif
   
/*
 * TODO: Implelment time counter and eviction init.
 *  

#if TIME_SOURCE == TIME_SOURCE_PERF
    perf_init(*session, args);
#elif TIME_SOURCE == TIME_SOURCE_THREAD_COUNTER
    thread_counter_init(*session, args);
#endif
    libflush_eviction_init(*session, args);
*/
    return true;
}


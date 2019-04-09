#include "timing.h"
#include <linux/perf_event.h>


bool perf_init(struct libflush_session_t *session, struct libflush_session_args_t *args) {

   static struct perf_event_attr attr;
   attr.type = PERF_TYPE_HARDWARE;
   attr.config = PERF_COUNT_HW_CPU_CYCLES;
   attr.size = sizeof(attr);
   attr.exclude_kernel = 1;
   attr.exclude_hv = 1;
   attr.exclude_callchain_kernel = 1;

   session->perf.fd = syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0);
   assert(session->perf.fd >= 0);
   return true;
}

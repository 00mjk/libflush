#ifndef TIMING_H
#define TIMING_H

#include "libflush.h"


bool perf_init(struct libflush_session_t *, struct libflush_session_args_t *);
bool thread_counter_init(struct libflush_session_t *, struct libflush_session_args_t *);

#endif


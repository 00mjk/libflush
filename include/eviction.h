#ifndef EVICTION_H
#define EVICTION_H

#include "libflush.h"

/*
 * Init eviction process.
 */

bool libflush_eviction_init(struct libflush_session_t *, struct libflush_session_args_t *);


/*
 * Terminate eviction process.
 */

bool libflush_eviction_terminate(struct libflush_session_t *);


/*
 * Evict an address.
 */

void libflush_eviction_evict(struct libflush_session_t *, void *);

/*
 * Prime a cache set.
 */

void libflush_eviction_prime(struct libflush_session_t *, size_t);

/*
 * Probe a cache set.
 */

void libflush_eviction_probe(struct libflush_session_t *, size_t);

#endif

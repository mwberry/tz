#ifndef LIBTZ_H

#define LIBTZ_H

#ifndef NETBSD_INSPIRED
# define NETBSD_INSPIRED 1
#endif

#include <time.h>

/*
** This file is in the public domain.
** These definitions were extracted from private.h to expose the _z
** variants of functions to consumers of libtz.a. This appears to be
** against the intent of the original author, but the value of the
** _z variants compared to the POSIX versions is enormous.
*/

/*
** Define functions that are ABI compatible with NetBSD but have
** better prototypes.  NetBSD 6.1.4 defines a pointer type timezone_t
** and labors under the misconception that 'const timezone_t' is a
** pointer to a constant.  This use of 'const' is ineffective, so it
** is not done here.  What we call 'struct state' NetBSD calls
** 'struct __state', but this is a private name so it doesn't matter.
*/
#if NETBSD_INSPIRED
typedef struct state *timezone_t;
struct tm *localtime_rz(timezone_t restrict, time_t const *restrict,
			struct tm *restrict);
time_t mktime_z(timezone_t restrict, struct tm *restrict);
timezone_t tzalloc(char const *);
void tzfree(timezone_t);
timezone_t tzdup(timezone_t);
# ifdef STD_INSPIRED
#  if TZ_TIME_T || !defined posix2time_z
time_t posix2time_z(timezone_t, time_t) ATTRIBUTE_PURE;
#  endif
#  if TZ_TIME_T || !defined time2posix_z
time_t time2posix_z(timezone_t, time_t) ATTRIBUTE_PURE;
#  endif
# endif
#endif

#endif /* !defined LIBTZ_H */

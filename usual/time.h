/*
 * Theme include for time.
 *
 * Copyright (c) 2007-2009 Marko Kreen, Skype Technologies OÜ
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */ 

/** * @file
 *
 * Time-related functionality.
 */

#ifndef _USUAL_TIME_H_
#define _USUAL_TIME_H_

#include <usual/base.h>

#include <sys/time.h>
#include <time.h>

/** Type to hold microseconds. */
typedef uint64_t usec_t;

/** How many microseconds in a second. */
#define USEC ((usec_t)1000000)

/** Convert usec timestamp to ISO timestamp with millisecond precision: YYYY-mm-dd hh:mm:ss.SSS */
char *format_time_ms(usec_t time, char *dst, unsigned dstlen);
/** Convert usec timestamp to ISO timestamp with second precision: YYYY-mm-dd hh:mm:ss */
char *format_time_s(usec_t time, char *dst, unsigned dstlen);

/** Query system time */
usec_t get_time_usec(void);

/** Query cached system time */
usec_t get_cached_time(void);
/** Forget cached system time, next call will fill it. */
void reset_time_cache(void);

#ifdef WIN32
/** Compat: gettimeofday() */
int gettimeofday(struct timeval * tp, void * tzp);
/** Compat: localtime_r() */
struct tm *localtime_r(const time_t *tp, struct tm *buf);

#ifndef HAVE_USLEEP
/** Compat: usleep() */
static inline void usleep(long usec) { Sleep(usec / 1000); }
#endif

/** Compat: rusage for win32 */
struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
};

#define RUSAGE_SELF 0
/** Compat: getrusage() for win32 */
int getrusage(int who, struct rusage *dst);

#endif

#endif

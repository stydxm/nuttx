/****************************************************************************
 * include/strings.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __INCLUDE_STRINGS_H
#define __INCLUDE_STRINGS_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include <string.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Compatibility definitions
 *
 * Marked LEGACY in Open Group Base Specifications Issue 6/
 * IEEE Std 1003.1-2004
 * Removed from Open Group Base Specifications Issue 7/
 * IEEE Std 1003.1-2008
 */

#ifndef bcmp /* See mm/README.txt */
#define bcmp(b1,b2,len)  memcmp(b1,b2,(size_t)len)
#endif

#ifndef bcopy /* See mm/README.txt */
#define bcopy(b1,b2,len) memmove(b2,b1,len)
#endif

#ifndef bzero /* See mm/README.txt */
#define bzero(s,n)       memset(s,0,n)
#endif

#define strcasecmp_l(s1, s2, l)     strcasecmp(s1, s2)
#define strncasecmp_l(s1, s2, n, l) strncasecmp(s1, s2, n)

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

int ffs(int j);

#ifdef CONFIG_HAVE_BUILTIN_FFS
#  define ffs(j)  __builtin_ffs(j)
#elif defined (CONFIG_HAVE_BUILTIN_CTZ)
#  define ffs(j)  (__builtin_ctz(j) + 1)
#endif

int ffsl(long j);

#ifdef CONFIG_HAVE_BUILTIN_FFSL
#  define ffsl(j) __builtin_ffsl(j)
#elif defined (CONFIG_HAVE_BUILTIN_CTZ)
#  define ffsl(j) (__builtin_ctzl(j) + 1)
#endif

#ifdef CONFIG_HAVE_LONG_LONG

int ffsll(long long j);

#  ifdef CONFIG_HAVE_BUILTIN_FFSLL
#    define ffsll(j)  __builtin_ffsll(j)
#  elif defined (CONFIG_HAVE_BUILTIN_CTZ)
#    define ffsll(j)  (__builtin_ctzll(j) + 1)
#  endif

#endif

int fls(int j);

#ifdef CONFIG_HAVE_BUILTIN_CLZ
#  define fls(j)  ((8 * sizeof(int)) - __builtin_clz(j))
#endif

int flsl(long j);

#ifdef CONFIG_HAVE_BUILTIN_CLZ
#  define flsl(j)  ((8 * sizeof(long)) - __builtin_clzl(j))
#endif

int flsll(long long j);

#ifdef CONFIG_HAVE_LONG_LONG
#  ifdef CONFIG_HAVE_BUILTIN_CLZ
#    define flsll(j)  ((8 * sizeof(long long)) - __builtin_clzll(j))
#  endif
#endif

unsigned int popcount(unsigned int j);
unsigned int popcountl(unsigned long j);
unsigned int popcountll(unsigned long long j);

FAR char *index(FAR const char *s, int c);
FAR char *rindex(FAR const char *s, int c);

int strcasecmp(FAR const char *, FAR const char *);
int strncasecmp(FAR const char *, FAR const char *, size_t);

#undef EXTERN
#if defined(__cplusplus)
}
#endif
#endif /* __INCLUDE_STRINGS_H */

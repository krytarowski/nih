/*-
 * Copyright (c) 2017 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Kamil Rytarowski.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NETBSD_COMPAT_H
#define _NETBSD_COMPAT_H

#include <inttypes.h>

typedef int8_t __haiku_int8;
typedef int16_t __haiku_int16;
typedef int32_t __haiku_int32;
typedef int64_t __haiku_int64;

typedef uint8_t __haiku_uint8;
typedef uint16_t __haiku_uint16;
typedef uint32_t __haiku_uint32;
typedef uint64_t __haiku_uint64;

#if _LP64
typedef uint64_t	__haiku_phys_addr_t;
typedef uint64_t	__haiku_generic_addr_t;
#else
typedef uint32_t	__haiku_phys_addr_t;
typedef uint32_t	__haiku_generic_addr_t;
#endif

typedef	unsigned long	addr_t;

#define  __HAIKU_PRI_PREFIX_32           "l"
#define  __HAIKU_PRI_PREFIX_64           "ll"
#define  __HAIKU_PRI_PREFIX_ADDR         "l"

#ifndef SIZE_MAX
#define SIZE_MAX (size_t)(-1)
#endif

#ifndef INT32_MAX
#define INT32_MAX 0x7fffffff
#endif

#ifndef INT32_MIN
#define INT32_MIN (-0x7fffffff-1)
#endif

#ifndef SYMLOOP_MAX
#define	SYMLOOP_MAX				(16)
#endif

#ifndef O_RWMASK
#define O_RWMASK          O_ACCMODE
#endif

#ifndef O_NOTRAVERSE
#define   O_NOTRAVERSE    0x2000          /* do not traverse leaf link */
#endif

#define HAIKU_TARGET_PLATFORM_HAIKU

#endif /* !_NETBSD_COMPAT_H */

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

#ifndef EOPNOTSUPP
#define EOPNOTSUPP 0
#endif

#ifndef BLOCKER_ALWAYS_SEMAPHORE_STYLE
#define BLOCKER_ALWAYS_SEMAPHORE_STYLE  0
#endif

#define _kern_transfer_area(a,b,c,d) 0
#define _kern_reserve_address_range(a,b,c) 0
#define _kern_get_safemode_option(a,b,c) 0
#define _kern_create_dir(a,b,c) 0
#define _kern_create_symlink(a,b,c,d) 0
#define _kern_read_stat(a,b,c,d,e) 0
#define _kern_close(a) 0
#define _kern_read_dir(a,b,c,d) 0
#define _kern_rewind_dir(a) 0
#define _kern_open_dir(a,b) 0
#define _kern_open_dir_entry_ref(a,b,c) 0
#define _kern_read_link(a,b,c,d) 0
#define _kern_rename(a,b,c,d) 0
#define _kern_open_parent_dir(a,b,c) 0
#define _kern_dup(a) 0
#define _kern_unlink(a,b) 0
#define _kern_remove_dir(a,b) 0
#define _kern_write_stat(a,b,c,d,e,f) 0
#define _kern_seek(a,b,c) 0
#define _kern_write(a,b,c,d) 0
#define _kern_read(a,b,c,d) 0
#define _kern_open(a,b,c,d) 0
#define _kern_open_entry_ref(a,b,c,d,e) 0
#define _kern_open_attr_dir(a,b,c) 0
#define _kern_rename_attr(a,b,c,d) 0
#define _kern_unlock_node(a) 0
#define _kern_fsync(a) 0
#define _kern_remove_attr(a,b) 0
#define _kern_lock_node(a) 0
#define _kern_start_watching(a,b,c,d,e) 0
#define _kern_stop_notifying(a,b) 0
#define _kern_stop_watching(a,b,c,d) 0
#define _kern_entry_ref_to_path(a,b,c,d,e) 0
#define _kern_open_query(a,b,c,d,e,f) 0
#define _kern_write_fs_info(a,b,c) 0

#endif /* !_NETBSD_COMPAT_H */

#ifndef _LINUX_THREADS_H
#define _LINUX_THREADS_H

#include <linux/config.h>

/*
 * The default limit for the nr of threads is now in
 * /proc/sys/kernel/threads-max.
 */
 
/*
 * Maximum supported processors that can run under SMP.  This value is
 * set via configure setting.  The maximum is equal to the size of the
 * bitmasks used on that platform, i.e. 32 or 64.  Setting this smaller
 * saves quite a bit of memory.
 */
#ifdef CONFIG_SMP
// This is the number of logical CPUs (or logical processors).
// A physical processor (or a physical package) can have multiple 
// logical processors (if a physical processor has 4 cores and 
// each core has 2 hyper-threads, the physical processor has 
// totally 8 logical processors). And a host can have multiple 
// physical processors. --Will
#define NR_CPUS		CONFIG_NR_CPUS
#else
#define NR_CPUS		1
#endif

#define MIN_THREADS_LEFT_FOR_ROOT 4

/*
 * This controls the default maximum pid allocated to a process
 */
#define PID_MAX_DEFAULT 0x8000

/*
 * A maximum of 4 million PIDs should be enough for a while:
 */
#define PID_MAX_LIMIT (sizeof(long) > 4 ? 4*1024*1024 : PID_MAX_DEFAULT)

#endif

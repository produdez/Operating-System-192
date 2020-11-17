#include "procsched.h"
#include <linux/kernel.h>
#include <sys/syscall.h>

long procsched(pid_t pid, struct proc_segs* info)
{
	return syscall(377,pid,info);
}

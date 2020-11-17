#include<linux/linkage.h> //the declaration of struct and this file
#include<linux/sched.h> // needed for task_struct and sched_info
#include<linux/kernel.h> // needed for KERN_INFO
struct proc_segs{
  unsigned long mssv;
  unsigned long pcount;
  unsigned long long run_delay;
  unsigned long long last_arrival;
  unsigned long long last_queued;
};

struct task_struct* task;
asmlinkage long sys_procsched(int pid, struct proc_segs* info){
  //TODO: Implement
  printk(KERN_INFO "Starting kernel syscall!\n");
  printk(KERN_INFO "ID: %d \n",pid);

  task = pid_task(find_vpid(pid), PIDTYPE_PID);
  if(!task) return -1;
  info->mssv= 1852545;
  info->pcount = task->sched_info.pcount;
  info->run_delay = task->sched_info.run_delay;
  info->last_arrival = task->sched_info.last_arrival;
  info->last_queued = task->sched_info.last_queued;

  printk(KERN_INFO "MSSV: %lu\n", info->mssv);
  printk(KERN_INFO "pcount: %lu\n",info->pcount);
  printk(KERN_INFO "run_delay: %llu\n", info->run_delay);
  printk(KERN_INFO "last_arrival: %llu\n",info->last_arrival);
  printk(KERN_INFO "last_queued: %llu\n",info->last_queued);

  return 0;
}

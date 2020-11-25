

# Introduction

This is a modification of the xv6 operating system in which the following features have been implemented:

    waitx system call
    getpinfo system call
    ps syste call showing all the information
    First-come-first-serve CPU scheduler
    Priority-based CPU scheduler
    Multi-level-feedback-queue CPU scheduler


# Compiling the code
Run

```bash
$ make qemu 
or
$ make qemu SCHEDFLAG=<scheduler>
```
Note: If any problems do clean the qemu as follows:
```
make clean
make
make qemu
```

where `SCHEDUFLAG` may be FCFS, PBS, DEFAULT(Round Robin), or MLFQ.

# Task1
* waitx syscall
* ps syscall

# waitx syscall
i/p- `time` command
o/p will be runtime and waittime of process
For implementing waitx syscall in the `struct proc`, some values were defined in `proc.h`
Also intialized some variables in `allocproc()` in `proc.c`

In function `waitx` simply we updated the times in `struct proc` and rest is same as `wait`

# ps syscall


`cprintf("pid \t name \t stat \t    priority \t   ctime \t rtime \t wtime \t   num_run \t cur_queue \t q[0] \t q[1] \t q[2] \t q[3] \t q[4]\n" );`

 The ps syscall gives a detailed list of all the processes present in the system at that particular instant. It loops through the ptable to obtain the details of the processes.

 Similar to waitx, we maintain the required info in the `struct proc` and obtain the info from process table whenever this syscall is called as we created a user progra to called that function.thus we get pinfo information

# Task 2
* The syscall `set_priority` allows changing the priority of a process. It simply modifies the process table entry for the given process that the scheduler then uses while scheduling.


## First come - First Served (FCFS)
- This is a non preemptive policy
- Iterate through the process table to find the process with min creation time and check if the process found is runnable, if it is, execute it.


# Priority Based scheduler
It chooses the process with minimum `priority` from the `struct proc`. All processes are given a default priority of 60 when allocated.
* the code for the following is in the proc.c

# MLFQ

declared 5 queues in proc.c.these contain process which is running.added the process queue where the process is runnable also aging is done to prevent the starvation by iterating 1-4 queues.then we iterate over all the queues in order, increase the tick associated with that process and its number of runs also made some changes in  trap.c file. 

# user files are
 `test.c
    test_priority.c
    ps.c
    pinfo.c`

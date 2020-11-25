#include "types.h"
#include "stat.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        printf(2,"Specify PID for pinfo\n");
    
    else
    {
        struct proc_stat p;
            
        if (getpinfo(&p, atoi(argv[1]))  == -1)
            printf(2, "Process with PID %d does not exist!\n", atoi(argv[1]));
        
        else 
        {
            printf(1, "Process with PID=%d has\nRunTime=%d\nNum_Run=%d\n",p.pid, p.runtime, p.num_run);
            #ifdef MLFQ
                printf(1, "Queue no=%d\nThe ticks received in each queue are:\n",p.current_queue);
                for(int i=0; i<5; i++)
                    printf(1, "%d: %d\n", i, p.ticks[i]);
            #endif
        }
    }
    
    exit();
}
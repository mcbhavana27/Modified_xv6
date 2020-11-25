
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define ll volatile int
#define MAX 100000000

int main(void) 
{
    
    for (int i = 0; i < 5; i++) 
    {
        int pid = fork();
        if (pid == 0) 
        {
            #ifdef PBS
                int my_pid = getpid();
                set_priority(my_pid, i*10);
            #endif
            ll x = 0;
            for (ll y = 0; y < MAX; y++) 
                x = (x+y) %147;

            exit();
        }
    }
    exit();
}
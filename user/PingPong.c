// Shell.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

// Parsed command representation


int main(int argc, char *argv[])
{
    char massage='-';  
    int P1[2];
    int P2[2];
    
    pipe(P1);
    pipe(P2);

    if (fork() == 0)
    {
        char buf;
        int res = 0;
        while(!res){ 
            res = read(P1[0],&buf,1);
        }
        int pid = getpid();
        printf("%d: received ping\n",pid);
        close(P1[0]);
        write(P2[1],&massage,1);
        close(P2[1]);
    }
    else
    {
        write(P1[1],&massage,1);
        close(P1[1]);
        char buf;
        int res = 0;
        while(!res){ 
            res = read(P2[0],&buf,1);
        }
        int pid = getpid();
        printf("%d: received pong\n",pid);
        close(P2[0]);
        exit(0);
    }
    exit(0);
}




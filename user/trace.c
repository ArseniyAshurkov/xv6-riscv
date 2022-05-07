#include "kernel/types.h" 
#include "kernel/stat.h" 
#include "user/user.h" 
#include "kernel/fcntl.h" 
 
void 
main(int argc, char **argv) 
{   char *args[10];
    for(int i=2;i<argc;i++)
    {
        args[i-2]=argv[i];
    }
    args[argc-2]=0;
    int mask = atoi(argv[1]);
    trace(mask);
    exec(argv[2], args);
}

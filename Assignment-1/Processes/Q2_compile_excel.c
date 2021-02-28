#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    
    pid_t pid=fork();
    if (pid==0) { 
        static char *argv[]={"echo","Hello, Welcome All",NULL};
        execv("/bin/echo",argv);
        exit(127); 
    }
    else { 
        waitpid(pid,0,0);
    }
    return 0;
}
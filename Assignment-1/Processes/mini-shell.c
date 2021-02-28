#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 

int main() 
{       int exec_pid;
        char *args[]={"./EXEC",NULL}; 
        execvp(args[0],args); 
        printf("Finishing Now........."); 
          int status;int pid;
pid = fork();
if (pid == 0)
{
    execl("/bin/sh", "sh", "-c", "ls -l *.c", NULL);
    _exit(EXIT_FAILURE);
}
else if (pid < 0)
    status = -1;
else
    if (waitpid(pid, &status, 0) != pid)
        status = -1;
return status;
} 
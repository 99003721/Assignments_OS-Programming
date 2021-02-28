#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <sys/mman.h>
  
int main() 
{ 
    const int SIZE = 4096; 
    const char* name = "OS"; 
    const char* message_0 = "Welcome"; 
    const char* message_1 = "Hello"; 
    int fd_sinnal_sinnal; 
    void* ptr; 
    fd_sinnal = shm_open(name, O_CREAT | O_RDWR, 0666); 
    ftruncate(fd_sinnal, SIZE); 
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd_sinnal, 0); 
    sprintf(ptr, "%s", message_0); 
    ptr =ptr + strlen(message_0); 
    sprintf(ptr, "%s", message_1); 
    ptr = ptr + strlen(message_1); 
    return 0; 
} 
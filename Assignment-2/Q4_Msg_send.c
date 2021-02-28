#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#define MAX 10 
struct msg_temp_buffer { 
	long msg_data; 
	char msg_response[100]; 
} message_data; 
int main() 
{ 
	key_t key; 
	int msg_id; 
	key = ftok("progfile", 65); 
	msg_id = msgget(key, 0666 | IPC_CREAT); 
	message_data.msg_data = 1; 
	printf("Write Data : "); 
	fgets(message_data.msg_response,MAX,stdin); 
	msgsnd(msg_id, &message_data, sizeof(message_data), 0); 
	printf("All Data send is : %s \n", message_data.msg_response); 
	return 0; 
} 

#include <sys/ipc.h> 

#include <stdio.h> 
#include <sys/msg.h> 
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
	msgrcv(msg_id, &message_data, sizeof(message_data), 1, 0); 
	printf("Data Received is : %s \n", message_data.msg_response); 
	msgctl(msg_id, IPC_RMID, NULL); 
	return 0; 
} 

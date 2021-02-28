#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
 FILE *file_source,*file_destination;
 int ch;
 if(argc< 0)
 {
  perror("open");
  return 1;
 }
 file_source=fopen(argv[1],"r");
 if(file_source==NULL)
 {
  perror("open");
  return 1;
 }
 file_destination=fopen(argv[2],"w");
 if(file_destination==NULL)
 {
 perror("open");
  fclose(file_source);
  return 1;
 }

 while(1)
 {
  ch=fgetc(file_source);
  if (feof(file_source)) break;
  fputc(ch,file_destination);
 }
printf("File Copied successfully");
 fclose(file_source);
 fclose(file_destination);
 return 0;
}
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
main()
{ ls command used in linux like systems
printf(“Before execl \n”);
execl(“/bin/ls”,”ls”,(char*)0);
printf(“After Execl\n”);

} 

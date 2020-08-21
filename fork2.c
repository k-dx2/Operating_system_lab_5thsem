#include<stdio.h>
#include<unistd.h>

int main()
{
 int pid;
 pid=fork();
 printf("%d\n",pid);
if(pid==0)
 {
  printf("In the child process\n");
 }
else
{
 printf("In the parent process\n");
}

return 0;}

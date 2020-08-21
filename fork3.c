#include<stdio.h>
#include<unistd.h>
int main()
{
 int pid;
 pid=fork();

 if(pid==0)
 {
  printf("In the child process\n");
  printf("Child PID %d\n",getpid());
  printf("Parent PID %d\n",getppid());
}
else

{   printf("In the Parent  process\n");
    printf("Parent PID %d\n",getpid());
    printf("Child PID %d\n",pid);

}
return 0;}


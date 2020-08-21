#include<stdio.h>
#include<unistd.h>

int main()
{
 char* args[]={"./home/kunal/os","./demo","./hello",NULL};
 execlp(args[0],args[1],args[2],NULL);
 return 0;
}



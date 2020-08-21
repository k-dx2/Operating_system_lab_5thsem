#include<stdio.h>
#include<unistd.h>
# define n 10

int main()
{
char line[n];
int fd[2],a,b;
pid_t c;
printf("Enter a number \n");
scanf("%d",&a);
pipe(fd);
close(fd[1]);
sprintf(line,"%d",a);
write(fd[1],line,n);

if((c=fork())==0)
{
read(fd[0],line,n);
sscanf(line,"%d",&b);
printf("The number entered in parent is \n");
printf("%d",b);


}

return 0;
}

#include<stdio.h>
#include<unistd.h>

#define max 10

void main()
{ int fd[2];
  int n=0;
  int i;
  char line[max];

  pipe(fd);

  if(fork()==0)
    {
       close(fd[0]);
       for(i=0;i<15;i++)
     {
       sprintf(line,"%d",n);
       write(fd[1],line,max);
       n++;
	sleep(2);
      }
    }
  else
    {	close(fd[1]);
	for(i=0;i<15;i++)
        {	 
        printf("\t\t\t Parent trying to read pipe\n");
	read(fd[0],line,max);
        sscanf(line,"%d",&n);
 	printf("\t\t\t Parent reads %d\n",n);
        }
    }    
}

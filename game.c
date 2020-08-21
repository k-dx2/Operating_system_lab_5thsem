#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
#define MIN 1
#define MAX 2
#define n 10

int randoms(int lower, int upper)
{
   int num = (rand() %(upper - lower + 1)) + lower;
    return num;
}

void main()
{
  int fd1[2],fd2[2],i,choice,a1,a2,b1,b2,flag = 0;
  int s1=0,s2=0;
  char line1[n];
  char line2[n];
  pipe(fd1);
  pipe(fd2);
  pid_t C,D;

if((C=fork()) == 0)
{
  flag = 1;

}
else
{
    if((D=fork())== 0)
      {
          flag = 2;
          srand(time(NULL));
      }
}


while(1)
{
  if(flag==1)
  {
    close(fd1[0]);
    a1=randoms(0,100);
    //a1 is randomly generated no
    sprintf(line1,"%d",a1);
    write(fd1[1],line1,n);
    printf("%d",a1);

  }
else if(flag==2)
{   close(fd2[0]);
    b1=randoms(0,100);
    //b1 is randomly generated no
    sprintf(line2,"%d",n);
    write(fd2[1],line2,b1);
    printf("%d",b1);

}

else
{
  if(s1==10||s2==10)
  {  if(s1==10)
    {printf("\n\nC WINS\n");
     kill(C,SIGKILL);
    }
   else
   { printf("\n\nD WINS\n");
     kill(D,SIGKILL);
   }
    exit(1);
   }


  close(fd1[1]);
  close(fd2[1]);
  read(fd1[0],line1,n);
  sscanf(line1,"%d",&a2);
  read(fd2[0],line2,n);
  sscanf(line2,"%d",&b2);

  choice =randoms(1,2);
  if(choice==MIN)
  { printf("\nThe flag choosen MIN ");
    printf("\nthe score of C %d and D %d",s1,s2);
    printf("\nfrom C %d and from D %d ",a2,b2);

    if(a2<b2)
    {  s1++;
       printf("\nCHild C gets the point\n");
     }

    else if(a2>b2)
       {  s2++;
            printf("\nCHild D gets the point\n");
        }

      }

 if(choice==MAX)
  { printf("\nThe flag choosen is MAX");
    printf("\nthe score of C %d and D %d",s1,s2);
    printf("\nfrom C %d and from D %d ",a2,b2);

   if(a2>b2)
     { s1++;
       printf("\nCHild C gets the point\n");
     }

   else if(a2<b2)
      {s2++;
        printf("\nCHild D gets the point\n");
      }

      }




}
}
}

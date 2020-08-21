#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>

int func(int a[],int l,int r)
{
  int n,m,max,i,x1,x2,status,pid1,pid2;

  n=r-l+1;

  m=(r+l)/2;


 if(n<10)
  {
    max=a[l];
    for(i=l+1;i<=r;i++)
      {
        if(a[i]>max)
          max=a[i];

       }

       return max;

   }

  else
   {

     if((pid1=fork())==0)
       {
         x1=func(a,l,m);
         printf("The PID is %d , The PPID is %d ,The Maximum in the range %d to %d is %d \n",getpid(),getppid(),l,m,x1);
         exit(x1);
       }
       waitpid(pid1,&status,0);
       x1=WEXITSTATUS(status);

      if((pid2=fork())==0)
      {
        x2=func(a,m+1,r);
        printf("The PID is %d , The PPID is %d ,The Maximum in 2the range %d to %d is %d \n",getpid(),getppid(),m+1,r,x2); 

        exit(x2);
      }

      waitpid(pid2,&status,0);
      x2=WEXITSTATUS(status);




      if(x1>x2)

            return x1;

      else
            return x2;


   }
}

int main()
{
  int i,j,n,a[100],c;
  printf("Enter the number of elements\n");
  scanf("%d",&n);

  srand(time(0));
  for(i=0;i<n;i++)
  a[i]=rand()%128;

  printf("The array elements are \n");

  for(j=0;j<n;j++)
  printf("%d ",a[j]);
  printf("\n");

  c=func(a,0,n-1);
  printf("The maximum in the array is %d\n",c);




  return 0;


}

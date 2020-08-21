
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int a[40][40], b[40][40];
int r1[40][40],r2[40][40];
int res[40][40];
int n;

void *sum()
{ int i,j;
  
  for( i=0;i<n;i++)
   for(j=0;j<n;j++)
   { 
    r1[i][j]=a[i][j]+b[i][j];
   }
   
   printf("\nThe Result of sum");

  for( i=0;i<n;i++)
   { printf("\n");
      for(j=0;j<n;j++)
     {  printf("%d  ",r1[i][j]);
        }
         }
   
    printf("\n"); 
 pthread_exit(NULL);
  
}

void *diff()
{ int i,j;
 
  for( i=0;i<n;i++)
   for(j=0;j<n;j++)
   {
    r2[i][j]=a[i][j]-b[i][j];
   }
   
   printf("\nThe Result of difference");
   
   for( i=0;i<n;i++)
   { printf("\n");
      for(j=0;j<n;j++)
     {  printf("%d  ",r2[i][j]);
        }
        }
  printf("\n");
  pthread_exit(NULL);
  
}

void mul(int n)
{
 int i,j,k;
 
 for (i=0;i<n;i++) 
    { for (j=0;j<n;j++) 
        {   res[i][j] = 0; 
            for (k = 0; k<n;k++) 
                res[i][j] += r1[i][k]*r2[k][j]; 
        } 
    } 
    
   printf("\nThe Result");
   
   for( i=0;i<n;i++)
   { printf("\n");
      for(j=0;j<n;j++)
     {  printf("%d  ",res[i][j]);
        }
    
 }   
    
} 

int main()
{
int i,j;

pthread_t pid1,pid2;
int rc1,rc2;
printf("Enter the number of elememnts\n");
scanf("%d",&n);
printf("Enter the elememnts of first matix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
   {scanf("%d",&a[i][j]);  }
   
printf("\nFirst Matrix");
for( i=0;i<n;i++)
   { printf("\n");
      for(j=0;j<n;j++)
     {  printf("%d  ",a[i][j]);
        }
         }
       

printf("\n\nEnter the elements of second matix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
   {    scanf("%d",&b[i][j]);}

printf("\nSecond Matrix");
for( i=0;i<n;i++)
   { printf("\n");
      for(j=0;j<n;j++)
     {  printf("%d  ",b[i][j]);
        }
         }
        printf("\n");


pthread_create(&pid1,NULL,sum,NULL);
pthread_create(&pid2,NULL,diff,NULL);
pthread_join(pid1,NULL);
pthread_join(pid2,NULL);


mul(n);

pthread_exit(NULL);

}





#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argv, char* argc[])
{
 int n=argv,val;
 val=atoi(argc[n-1]);
 val=val/2;
 printf("The value in half is \n",val);
 int i,j;
 if(n>2)
 {
   for(i=0;i<n-2;i++)
   {
    int len=strlen(argc[i+1]);
    len++;
    argc[i]=(char*)malloc(len*sizeof(char));
    
    for(j=0;j<len-1;j++)
    argc[i][j]=argc[i+1][j];
    
    
    }
 }
 
 
 

#include<stdio.h>
#include<unistd.h>

int main()
{
 printf("Before Forking\n");
 fork();
 printf("After Forking\n");
 }



#include<stdio.h>

     int main()

  {    int n,i,fact=1;
      float sum=0;
      printf("enter n");
      scanf("%d",&n);
       i=n;
      while(i>=1)
      {
          fact=fact*i;
      sum=sum+(float)(i-1)/fact ;
       i--;
      }

     printf("%f",sum);


   }

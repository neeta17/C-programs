// to find number is armstrong or not
#include <stdio.h>
#include<math.h>
  int arm(int n);

    int main()
    {   int n,sum;
    printf("enter n");
    scanf("%d",&n);
    sum =arm(n);
    if(n==sum)
       printf("%d is armstrong",n);

             else
                    printf("%d is not an armstrong",n);




    }
    int arm(int n)
    {
         int sum=0,dig;
         dig=n%10;
         sum=sum+(dig*dig*dig);
         n=n/10;

   return sum;
    }

#include <stdio.h>
int main()
{
     int i,n,sum=0,c=0;
     scanf("%d",&n);
     for(i=n;i>=1;i--)
     {
        if(n%i==0)
          {
             printf("%d ",i);
              sum+=i;
               c++;
           }
       }
         printf("%d ",c);
         printf("%d",sum);
}

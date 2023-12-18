#include <stdio.h>
#include <stdlib.h>
void oct_to_dec();


int main()
{
   oct_to_dec();
   return 0;
}


void oct_to_dec()
{
    int i,j,n=0,sum=0,t,m;

    char num[500];

    printf("Enter the Octal number: ");
    again:    // TO returen here again if user enter unvalid number
    scanf("%s",&num);
    if(num[0]!='-')
  {


    for(j=0;num[j]!='\0';j++)
    {
        n++;   //calculate number .....
    }

    n--;       //because we multiply *16^(n-1)

    for(i=0;num[i]!='\0';i++)
    {
        if(num[i]>='0'&&num[i]<='7') //check if num from 0 to 9
        {
            t=num[i]-48;           //convert num (0-9) to decimal number equvilant(0=48)
        }


        else if(num[i]<'0'||num[i]>'7')  //check if user enter unvalid number
        {
            printf("Number you enter is't valid \nEnter valid Octal number :");
            t=n=sum=0;  //put t,c,r=0 to read new number
            goto again;   // when user enter unvalid number return to read new number
        }

    sum=sum+t*pow(8,n);
    n--;
    }
    printf("\nThe decimal number is: %d \n",sum);
  }
  else
    printf("\nI can't convert negative numbers\n");
}

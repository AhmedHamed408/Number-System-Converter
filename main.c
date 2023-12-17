#include <stdio.h>
#include <stdlib.h>
void hex_to_dec();


int main()
{
  hex_to_dec();
   return 0;
}


void hex_to_dec()
{
    int i,j,n=0,sum=0,t,m;

    char num[500];

    printf("Enter the hexadecimal number: ");
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
        if(num[i]>='0'&&num[i]<='9') //check if num from 0 to 9
        {
            t=num[i]-48;           //convert num (0-9) to decimal number equvilant(0=48)
        }

        else if(num[i]>='A'&&num[i]<='F') //check if num A,B,C,D,E,F
        {
            t=num[i]-65+10;    //convert num (A-F) to hex number equvilant(A-F)
        }

        else if(num[i]>='a'&&num[i]<='f')  //check if num a,b,c,d,e,f
        {
            t=num[i]-97+10;   //convert num (a-f) to hex number equvilant(a-f)
        }

        else if((num[i]>='G'&&num[i]<='Z')||(num[i]>='g'&&num[i]<='z'))  //check if user enter unvalid number
        {
            printf("Number you enter is't valid \nEnter valid hexadecimal number :");
            t=n=sum=0;  //put t,c,r=0 to read new number
            goto again;   // when user enter unvalid number return to read new number
        }

    sum=sum+t*pow(16,n);
    n--;
    }
    printf("\nThe decimal number is: %d \n",sum);
  }
  else
    printf("\nI can't convert negative numbers\n");
}

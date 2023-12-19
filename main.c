#include <stdio.h>
#include <stdlib.h>
#include<math.h>   // for: pow(2,0) function
#include<string.h> // for: strlen() function

void hex2dec();
void oct2dec();
void dec2hex();
void dec2oct();
void Bin2Hex();
void Hex2Bin();
void dec2bin();
void bin2dec();

int main()
{
    int choose;
    char cont;

    again:
    printf("-------------------------------------------\n");
    printf(">>> Welcome to Number System Converter <<< \n");
    printf("-------------------------------------------\n\n");

    printf("Chose the number of process you want to do \n\n1- hex2dec \n2- oct2dec \n3- dec2hex \n4- dec2oct \n5- Bin2Hex \n6- Hex2Bin \n7- dec2bin  \n8- bin2dec ");
    printf("\n\nProcess number = ");
    scanf("%d",&choose);
    printf("\n\n");

    switch(choose)
    {
        case 1:
        hex2dec();
        break;

        case 2:
        oct2dec();
        break;

        case 3:
        dec2hex();
        break;

        case 4:
        dec2oct();
        break;

        case 5:
        Bin2Hex();
        break;

        case 6:
        Hex2Bin();
        break;

        case 7:
        dec2bin();
        break;

        case 8:
        bin2dec();
        break;

        default:
            printf("\nError: the number must be between 1 to 8.\n");
            printf("Press any key to continue... \n");
            getch();
            goto again;

    }
        again1:
        printf("You want to convert another number (y/n) ?  ");
        scanf("%s",&cont);

        if(cont=='y'||cont=='Y')
            {
                printf("\n");
                goto again;
            }
        else if(cont=='n'||cont=='N')
            {
                printf("\nOk, Good Bye\n");

            }
        else
            {
                printf("Unvalid Choice\n");
                goto again1;
            }

}


void hex2dec()
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

void oct2dec()
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
void dec2hex(){


    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Hexadecimal number: %X\n", decimalNumber);

}
void dec2oct()
{

int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

printf("Octal number: %o\n", decimalNumber);
}
void Bin2Hex() {

    char BinNum[100];
    int decimal = 0;
    int power = 1;
    char hexadecimal[100];
    int index = 0;


    printf("Enter Binary Number: \n");
    scanf("%s", BinNum);

    for (int i = 0; i < strlen(BinNum); i++) {
        if (BinNum[i] != '0' && BinNum[i] != '1') {
            printf("Invalid binary number.\n");
            return;
        }
    }

    for (int i = strlen(BinNum) - 1; i >= 0; i--) {
        if (BinNum[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }

    printf("Hexadecimal equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}
void Hex2Bin() {
    char binary[400];
    int binaryIndex = 0;
    char HexNum[100];


    printf("Enter Hexadecimal Number: \n");
    scanf("%s", HexNum);

    for (int i = 0; i < strlen(HexNum); i++) {
        char hexDigit = HexNum[i];


        int decimal;
        if (hexDigit >= '0' && hexDigit <= '9') {
            decimal = hexDigit ;
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            decimal = hexDigit - 'A' + 10;
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            decimal = hexDigit - 'a' + 10;
        } else {
            printf("Invalid hexadecimal number.\n");
            return;
        }


        for (int j = 3; j >= 0; j--) {
            binary[binaryIndex++] = (decimal & (1 << j)) ? '1' : '0';
        }
    }

    binary[binaryIndex] = '\0';

    printf("Binary equivalent: %s\n", binary);
}

void dec2bin()
{
    int num, bit=1,n;
    bit<<=31;
    printf("enter a decimal number: ");
    scanf("%d",&num);
    printf("\n\n");
    if(num>=0)
    {
        printf("the binary number = ");
        for(int i=1;i<=32;i++)
    {
      putchar(bit&num?'1':'0');
        num<<=1;
        if(i%4==0)
            printf(" ");
    }
     printf("\n\n");
    }
    else
    {
     int arr[32],arr2[32];
     int k=8;
     num*=-1;
     for(int i=0;i<=31;i++)
     {
      arr[i]=((num%2==1)?1:0);

        num/=2;

     }
     printf("the binary number = ");
     for(int i=0;i<=31;i++)
     {
         if(arr[i]==0)
            arr2[i]=arr[i];
         else
         {
             arr2[i]=1;
             k=i;
             break;
         }
     }

     for(int i=k+1;i<=31;i++)
     {
        arr2[i]=(arr[i]==0?1:0);
     }
     for(int i=31;i>=0;i--)
     {
         printf("%d",arr2[i]);
         if(i%4==0)
            printf(" ");
     }
     printf("\n\n");
    }
}

void bin2dec()
{
    int i=0,count=0,num=0,k;
    char  arr[100],a;
    printf(" enter the binary number then \"x\" in end : ");
    do   //read the binary number and stores it in array "arr[32]"
    {
       a=getche();

       if((a=='1')||(a=='0'))
       {
           arr[i]=a;
           i++;
           count++;

       }
       else
       {
           printf("\n the number %c not in binary system \n please, enter 0 & 1 only we will ignore the last number\"%C\"  ",a,a);
       }

    }while (a!='x');
    printf("\n\n");

     int arr2[count];

    if(arr[0]=='0')
    {
        int j=-2;
       for(int i=count;i>0;i--)
       {
           j++;
           if(arr[i]=='1')
           {
              num+=pow(2,j);

           }
       }
        printf("the decimal value equals:  %d\n\n",num);
    }
    else
    {
         int j=0;
     for(int i=count-1;i>=0;i--)
     {
      if(arr[i]=='0')
      {

          arr2[j]=0;
          j++;

      }
      else
      {
          arr2[j]=1;
          k=i;

          break;
      }
     }
     for(int i=k-1;i>=0;i--)
     {
        arr2[j+1]=((arr[i]=='0')?1:0);
        j++;
     }
     int f=-1 ,num=0;

       for(int i=0;i<count;i++)
       {
           f++;
           if(arr2[i]==1)
           {
              num+=pow(2,f);

           }
       }
       printf("the decimal value equals: -%d\n\n",num);
    }
}

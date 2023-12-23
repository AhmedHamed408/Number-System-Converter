#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // for: pow(2,0) function
#include <string.h> // for: strlen() function
#include <conio.h> //for: getchar

void hex2dec();
void dec2hex();
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

    printf("Chose the number of process you want to do \n\n1- Hex2Dec \n2- Hex2Bin \n3- Dec2Hex \n4- Dec2Bin \n5- Bin2Dec \n6- Bin2Hex  ");
    printf("\n\nProcess number = ");
    scanf("%d",&choose);
    printf("\n\n");

    switch(choose)
    {
    case 1:
        hex2dec();
        break;

    case 2:
        Hex2Bin();
        break;

    case 3:
        dec2hex();

        break;

    case 4:
        dec2bin();
        break;

    case 5:
        bin2dec();
        break;

    case 6:
        Bin2Hex();
        break;

    default:
        printf("\nError: the number must be between 1 to 6.\n");
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
        printf("Invalid Choice\n");
        goto again1;
    }

}


void hex2dec()
{
    int i,j,n=0,sum=0,t;

    char num[500];

    printf("Enter the hexadecimal number: ");
again:    // TO returen here again if user enter unvalid number
    scanf("%s",&num);


    for(j=0; num[j]!='\0'; j++)
    {
        n++;   //calculate number .....
    }

    n--;       //because we multiply *16^(n-1)

    for(i=0; num[i]!='\0'; i++)
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
    printf("\Decimal equivalent: %d \n",sum);
}



void dec2hex()
{


    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Hexadecimal equivalent: %X\n", decimalNumber);

}
void dec2oct()
{

    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Octal equivalent: %o\n", decimalNumber);
}
void Bin2Hex()
{

    char BinNum[100];
    int decimal = 0;
    int power = 1;
    char hexadecimal[100];
    int index = 0;


    printf("Enter Binary Number: ");
    scanf("%s", BinNum);

    for (int i = 0; i < strlen(BinNum); i++)
    {
        if (BinNum[i] != '0' && BinNum[i] != '1')
        {
            printf("Invalid binary number.\n");
            return;
        }
    }

    for (int i = strlen(BinNum) - 1; i >= 0; i--)
    {
        if (BinNum[i] == '1')
        {
            decimal += power;
        }
        power *= 2;
    }

    while (decimal > 0)
    {
        int remainder = decimal % 16;
        if (remainder < 10)
        {
            hexadecimal[index++] = remainder + '0';
        }
        else
        {
            hexadecimal[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }

    printf("Hexadecimal equivalent: ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}
void Hex2Bin()
{
    char binary[400];
    int binaryIndex = 0;
    char HexNum[100];


    printf("Enter Hexadecimal Number: ");
    scanf("%s", HexNum);

    for (int i = 0; i < strlen(HexNum); i++)
    {
        char hexDigit = HexNum[i];


        int decimal;
        if (hexDigit >= '0' && hexDigit <= '9')
        {
            decimal = hexDigit ;
        }
        else if (hexDigit >= 'A' && hexDigit <= 'F')
        {
            decimal = hexDigit - 'A' + 10;
        }
        else if (hexDigit >= 'a' && hexDigit <= 'f')
        {
            decimal = hexDigit - 'a' + 10;
        }
        else
        {
            printf("Invalid hexadecimal number.\n");
            return;
        }


        for (int j = 3; j >= 0; j--)
        {
            binary[binaryIndex++] = (decimal & (1 << j)) ? '1' : '0';
        }
    }

    binary[binaryIndex] = '\0';

    printf("Binary equivalent: %s\n", binary);
}

void dec2bin()  //the function that converts from decimal to binary
{
    int num, bit=1,n;
    bit<<=31;
    printf("Enter a decimal number: ");
    scanf("%d",&num);
    printf("\n\n");
    if(num>=0)          // if the decimal number is positive converts it to binary by using bitwise and prints it by putchar
    {
        printf("Binary equivalent: ");
        for(int i=1; i<=32; i++)
        {
            putchar(bit&num?'1':'0');
            num<<=1;
            if(i%4==0)
                printf(" ");
        }
        printf("\n\n");
    }
    else             // if the decimal number is negative
    {
        int arr[32],arr2[32];
        int k;
        num*=-1;
        for(int i=0; i<=31; i++)    //convert the value to binary in array "arr[]"
        {
            arr[i]=((num%2==1)?1:0);

            num/=2;

        }
        printf("Binary equivalent: ");
        for(int i=0; i<=31; i++)         // Make the two's complement to the binary number and save the Result in array "arr2[]"
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

        for(int i=k+1; i<=31; i++)
        {
            arr2[i]=(arr[i]==0?1:0);
        }
        for(int i=31; i>=0; i--)        //print the two's complement to the binary number from 'arr2[]'
        {
            printf("%d",arr2[i]);
            if(i%4==0)
                printf(" ");
        }
        printf("\n\n");
    }
}

void bin2dec()             // the function that converts from binary to decimal
{
    int i=0,count=0,num=0,k;
    char  arr[100],a;
again:
    printf("\nEnter the binary number : ");
    do                       //read the binary number and stores it in array "arr[32]"
    {
        a=getche();

        if((a=='1')||(a=='0')||(a==0x0D))
        {
            arr[i]=a;
            i++;
            count++;

        }
        else
        {
            printf("\n the number %c not in binary system \n please, enter 0 & 1 only ",a);
            i=count=0;
            goto again;
        }

    }
    while (a!=0x0D);
    printf("\n\n");

    int arr2[count];
    if(arr[0]=='0')        // test the first bit from left( To determine the signal is positive or negative)
    {
        // If "if(arr[0]=='0')" is true, the number is positive
        int j=-3;
        for(int i=count; i>0; i--)   // calculate the value of the positive decimal number
        {
            j++;
            if(arr[i]=='1')
            {
                num+=pow(2,j);

            }
        }
        printf("Decimal equivalent:  %d\n\n",num);
    }
    else            //if "if(arr[0]=='0')" is false,  the number is negative
    {
        int j=0;
        for(int i=count-1; i>=0; i--)  // Make the two's complement to the binary number and save the Result in array "arr2[]"
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
        for(int i=k-1; i>=0; i--)
        {
            arr2[j+1]=((arr[i]=='0')?1:0);
            j++;
        }
        int f=-2,num=0;

        for(int i=0; i<count; i++)   //  calculate the value of the decimal number after Making the two's complement to the binary number
        {
            f++;
            if(arr2[i]==1)
            {
                num+=pow(2,f);

            }
        }
        printf("Decimal equivalent: -%d\n\n",num+1);  // Print negative sign then the value
    }

}


#include <stdio.h>
#include <string.h>
typedef long int li;
int digit(char);
li romantodeci(char roman[]);
int decitoroman(li);

int main()
{
    int option;
    printf("Select a option: \n");
    printf("1. Addition \n");
    printf("2. Multiplication\n");
    printf("Enter your choice option number: ");
    scanf("%d", &option);
    if (option == 1)
    {
        char romannum1[1000], romannum2[1000];
        printf("Enter two roman numeral(CAPITALS): ");
        scanf("%s %s", romannum1, romannum2);
        long int decimalnum1 = romantodeci(romannum1);
        long int decimalnum2 = romantodeci(romannum2);
        if (decimalnum1 == -1 || decimalnum2 == -1)
        {
            return 1;
        }
        else
        {
            long int sum = decimalnum1 + decimalnum2;
            printf("Sum is: ");
            decitoroman(sum);
            printf("\n");
        }
    }
    else if (option == 2)
    {
        char romannum1[1000], romannum2[1000];
        printf("Enter two roman numeral(CAPITALS): ");
        scanf("%s %s", romannum1, romannum2);
        long int decimalnum1 = romantodeci(romannum1);
        long int decimalnum2 = romantodeci(romannum2);
        if (decimalnum1 == -1 || decimalnum2 == -1)
        {
            return 1;
        }
        else
        {
            long int product = decimalnum1 * decimalnum2;
            printf("Product is: ");
            decitoroman(product);
            printf("\n");
        }
    }

    return 0;
}

int digit(char ch)
{
    int val = 0;
    switch (ch)
    {
    case 'I':
        val = 1;
        break;
    case 'V':
        val = 5;
        break;
    case 'X':
        val = 10;
        break;
    case 'L':
        val = 50;
        break;
    case 'C':
        val = 100;
        break;
    case 'D':
        val = 500;
        break;
    case 'M':
        val = 1000;
        break;
    case '\0':
        val = 0;
        break;
    default:
        val = -1;
    }
    return val;
}
li romantodeci(char roman[])
{
    int i = 0;
    li num = 0;
    while (roman[i])
    {
        if (digit(roman[i]) < 0)
        {
            printf("Invalid roman literal");
            return -1;
        }
        if ((strlen(roman) - 1) > 2)
        {
            if (digit(roman[i]) < digit(roman[i + 2]))
            {
                printf("Invalid roman literal");
                return -1;
            }
        }
        if (digit(roman[i]) >= digit(roman[i + 1]))
        {
            num += digit(roman[i]);
        }
        else
        {
            num += digit(roman[i + 1]) - digit(roman[i]);
            i++;
        }
        i++;
    }
    return num;
}
int decitoroman(li num)
{
    if (num <= 0)
    {
        return -1;
    }
    while (num != 0)
    {
        if (num >= 1000)
        {
            printf("M");
            num -= 1000;
        }
        else if (num >= 900)
        {
            printf("CM");
            num -= 900;
        }
        else if (num >= 500)
        {
            printf("D");
            num -= 500;
        }
        else if (num >= 400)
        {
            printf("CD");
            num -= 400;
        }
        else if (num >= 100)
        {
            printf("C");
            num -= 100;
        }
        else if (num >= 90)
        {
            printf("XC");
            num -= 90;
        }
        else if (num >= 50)
        {
            printf("L");
            num -= 50;
        }
        else if (num >= 40)
        {
            printf("XL");
            num -= 40;
        }
        else if (num >= 10)
        {
            printf("X");
            num -= 10;
        }
        else if (num >= 9)
        {
            printf("IX");
            num -= 9;
        }
        else if (num >= 5)
        {
            printf("V");
            num -= 5;
        }
        else if (num >= 4)
        {
            printf("IV");
            num -= 4;
        }
        else if (num >= 1)
        {
            printf("I");
            num -= 1;
        }
    }
    return 1;
}
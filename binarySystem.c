#include <stdio.h>

int binaryproduct(int binary1, int binary2)
{
    int i = 0, remainder = 0, sum[20];
    int binaryprod = 0;

    while (binary1 != 0 || binary2 != 0)
    {
        sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    while (i >= 0)
        binaryprod = binaryprod * 10 + sum[i--];
    return binaryprod;
}

int main()
{
    int option;
    printf("Select a choice: \n");
    printf("1. Addition \n");
    printf("2. Multiplication\n");
    printf("Enter your choice option number: ");
    scanf("%d", &option);
    if (option == 1)
    {
        long binary1, binary2;
        int i = 0, remainder = 0, sum[20];

        printf("Enter the first binary number: ");
        scanf("%ld", &binary1);
        printf("Enter the second binary number: ");
        scanf("%ld", &binary2);
        while (binary1 != 0 || binary2 != 0)
        {
            sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
            remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
            binary1 = binary1 / 10;
            binary2 = binary2 / 10;
        }
        if (remainder != 0)
            sum[i++] = remainder;
        --i;
        printf("Sum of two binary numbers: ");
        while (i >= 0)
            printf("%d", sum[i--]);
    }
    else if (option == 2)
    {
        long binary1, binary2, multiply = 0;
        int digit, factor = 1;

        printf("Enter the first binary number: ");
        scanf("%ld", &binary1);
        printf("Enter the second binary number: ");
        scanf("%ld", &binary2);
        while (binary2 != 0)
        {
            digit = binary2 % 10;
            if (digit == 1)
            {
                binary1 = binary1 * factor;
                multiply = binaryproduct(binary1, multiply);
            }
            else
                binary1 = binary1 * factor;
            binary2 = binary2 / 10;
            factor = 10;
        }
        printf("Product of two binary numbers: %ld", multiply);
    }
    return 0;
}

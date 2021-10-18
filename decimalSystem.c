#include <stdio.h>

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
        long int num1, num2;
        printf("Enter two decimal integer numbers: ");
        scanf("%ld %ld", &num1, &num2);
        long int sum = num1 + num2;
        printf("Sum is: %ld \n", sum);
    }
    else if (option == 2)
    {
        long int num1, num2;
        printf("Enter two decimal integer numbers: ");
        scanf("%ld %ld", &num1, &num2);
        long int product = num1 * num2;
        printf("Product is: %ld \n", product);
    }
return 0;
}
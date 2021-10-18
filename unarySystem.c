#include <stdio.h>
#include <string.h>

int validunary(char unary[])
{
    int i = 0;
    while (unary[i])
    {
        if (unary[i] != '1')
        {
            return -1;
        }
        i++;
    }
    return 1;
}

int main()
{
    while (1)
    {
        int option;
        printf("Select a option: \n");
        printf("1. Addition \n");
        printf("2. Multiplication\n");
        printf("Enter your choice option number: ");
        scanf("%d", &option);
        if (option == 1)
        {
            char unary1[500], unary2[500];
            printf("Enter two unary no.s: ");
            scanf("%s %s", unary1, unary2);
            if (validunary(unary1) == 1 && validunary(unary2) == 1)
            {
                strcat(unary1, unary2);
                printf("Sum is: %s\n", unary1);
            }
        }
        else if (option == 2)
        {
            char unary1[500], unary2[500];
            printf("Enter two unary no.s: ");
            scanf("%s %s", unary1, unary2);
            if (validunary(unary1) == 1 && validunary(unary2) == 1)
            {
                printf("Product is: ");
                for (int i = 0; i < strlen(unary2); i++)
                {
                    printf("%s", unary1);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Exiting..");
            break;
        }
    }
    return 0;
}

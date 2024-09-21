#include<iostream>

int main(int argc, char* argv[])
{
        int x=0;
        scanf_s("%d", &x);
        printf("The next number for the number ");
        printf("%d", x);
        printf(" is ");
        printf("%d", x+1);
        printf(".");
        printf("\n");

        printf("The previous number for the number ");
        printf("%d", x);
        printf(" is ");
        printf("%d", x-1);
        printf(".");

        return EXIT_SUCCESS;
        
}

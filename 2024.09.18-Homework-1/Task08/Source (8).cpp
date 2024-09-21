#include<iostream>

int main(int argc, char* argv[])
{
        int x=0;
        scanf_s("%d", &x);
        printf("%d", x/100+(x%100)/10+x%10);
        
        return EXIT_SUCCESS;
        
}
#include <cstdio>

int main(int argc, char* argv[]) 

{
    
    int x=0, y=0;
    scanf("%d %d", &x, &y);
    
    if (x == 1 && y == 1) 
    {
        printf("0\n");
    } 
    else if (x == y) 
    {
        printf("2\n"); 
    }
    else printf ("1");

    return EXIT_SUCCESS;
    
}
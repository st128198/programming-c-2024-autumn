#include <stdio.h>
#include <stdlib.h>

int main() 

{
  
    int n = 0;
    scanf("%d", &n);
    int b[n];
    
    int c = 0;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++) 
    {
        if (b[i] <= 437) 
        {
            printf("Crash %d\n", i + 1);
            c = 1;
            break;
        }
    }

    if (c == 0) 
    {
        printf("No crash\n");
    }

    return EXIT_SUCCESS;
  
}

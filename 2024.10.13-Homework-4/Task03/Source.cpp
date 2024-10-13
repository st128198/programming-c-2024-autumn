#include <stdio.h>

int main() 

{
    
    int a[1000], i=0, n=0, x=0, y=0;

    scanf("%d %d", &n, &a[0]);
    x = a[0];
    y = a[0];

    for (i = 1; i < n; i++) 
    {
        scanf("%d", &a[i]);
        if (a[i] > x) 
            x = a[i];
        else if (a[i] < y) 
            y = a[i];
    }

    for (i = 0; i < n; i++) 
    {
        if (a[i] == x) 
            a[i] = y;
        printf("%d ", a[i]);
    }

    return EXIT_SUCCESS;
    
}

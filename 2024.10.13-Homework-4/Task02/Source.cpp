#include <stdio.h>

int main() 

{
    
    int a[1001], i=0, n=0, l=0, r=0, k=0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    scanf("%d %d", &l, &r);

    k = l;

    for(i = l + 1; i <= r; i++)
        if(a[i] > a[k]) 
            k = i;

    printf("%d %d\n", a[k], k);

    return EXIT_SUCCESS;
    
}

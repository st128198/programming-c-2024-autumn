#include <stdio.h>
#include <stdlib.h>

int main()

{
    
    long n=0, x=0, S0=0, S1=0, i=0;
    scanf("%ld", &n);
    
    S0 = S1 = 0;
    for (i = 1; i <= n; i++) 
    {
        scanf("%ld", &x);
        x > 0 ? S0++ : S1++;
    }

    printf("%ld\n", S0 < S1 ? S0 : S1);

    return EXIT_SUCCESS;
    
}

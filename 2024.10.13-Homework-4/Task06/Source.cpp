#include <stdio.h>

int v[100], n=0, m=-1, i=0, j=0, d=0;

#define x

int main() 

{
    
    x("%d", &n);

    for (i = 0; i < n; x("%d", &v[i++]));

    for (j = 0; j < n;) 
    {
        if ((n *= v[j++]) > m) 
        {
            m = n;
            d = j;
        }
    }
    
    printf("%d\n", d);
    
    return EXIT_SUCCESS;
    
}

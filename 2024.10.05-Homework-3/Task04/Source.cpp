#include <stdio.h>

int main() 

{
    
    int n=0;
    scanf("%d", &n);
    
    int v = 0, s = 0, vx = -1, a = 0, vm = 0;
    for (int i = 0; i < n; i++) 
    {
        a += 1;
        scanf("%d %d", &v, &s);
        if (s == 1) 
        {
            if (vm < v) 
            {
                vx = a;
                vm = v;
            }
        }
    }
    
    printf("%d\n", vx);
    
    return EXIT_SUCCESS;
    
}

#include <stdio.h>
#include <iomanip>

int main(int argc, char* argv[]) 

{
    
    int k=0;
    scanf("%d", &k);
    
    for (int i = 0; i < k; i++) 
    {
        int n=0, m=0;
        scanf("%d %d", &n, &m);
        double d = 19 * m + (n + 239) * (n + 366) / 2.0;
        
        if (d == (int)d) 
        {
            printf("%d\n", (int)d);
        } 
        else 
        {
            printf("%.6f\n", d);
        }
    }
    
    return EXIT_SUCCESS;
    
}

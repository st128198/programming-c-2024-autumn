#include <stdio.h>

int main() 

{
    
    int n=0, a=0, b=0, c=0, d=0;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    int x[1001], y[1001];
    for(int i = 1; i <= n; i++) 
    {
        x[i] = i; 
        y[i] = x[i];
    }
    
    for(int i = 0; i <= b - a; i++) 
    {
        x[a + i] = y[b - i];
    }
    
    for(int i = 1; i <= n; i++) 
    {
        y[i] = x[i];
    }
 
    for(int i = 0; i <= d - c; i++) 
    {
        x[c + i] = y[d - i];
    }
 
    for(int i = 1; i <= n; i++) 
    {
        printf("%d ", x[i]);
    }
    
    return EXIT_SUCCESS;
  
}

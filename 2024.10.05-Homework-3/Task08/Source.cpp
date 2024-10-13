#include <stdio.h>

int gcd(int m, int n) 

{
    
  while(m && n) {
        if (m < n) 
            n %= m; 
        else 
            m %= n;
    }
    return m + n;
}

int main() 

{
    int i, j, f0 = 0, f1 = 1;
    scanf("%d %d", &i, &j);

    for(i = gcd(i, j); i > 0; --i) 
    {
        int f = (f0 + f1) % 1000000000;
        f0 = f1;
        f1 = f;
    }

    printf("%d\n", f0);
  
    return EXIT_SUCCESS;
  
}

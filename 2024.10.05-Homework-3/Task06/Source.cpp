#include <stdio.h>

int nod(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    } 
    else 
    {
        return nod(b, a % b);
    }
}

int nok(int a, int b) 
{
    return a * b / nod(a, b);
}

int main()

{
    
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", nok(a, b));
   
    return 0;
    
}

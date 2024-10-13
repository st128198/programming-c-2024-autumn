#include <stdio.h>

int main() 

{
   
    int n=0, k=0, ans=0, a[101];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    k = ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            k++;
        else 
        {
            if (k > ans)
                ans = k;
            k = 0;
        }

    if (k > ans)
        ans = k;

    printf("%d\n", ans);

    return EXIT_SUCCESS;
    
}

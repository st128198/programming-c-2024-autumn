#include <stdio.h>
#include <vector>
#include <algorithm>

int main() 

{
    
    int n=0;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int x=0;
    scanf("%d", &x);

    printf("%d\n", count(a.cbegin(), a.cend(), x));

    return EXIT_SUCCESS;
    
}

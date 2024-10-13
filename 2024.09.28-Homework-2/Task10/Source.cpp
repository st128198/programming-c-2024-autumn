#include <bits/stdc++.h>

using namespace std;

int main()

{

    int k=0, c5 = 0, c3 = 0, s = 0;
    scanf("%d", &k);
    
    if(k == 6 || k == 3 || k == 9 || k == 12) {
        printf("%d %d\n", 0, k / 3);
        return 0;
    }

    while(s < k) 
    {
        s += 5;
        c5++;
        if((k - (c5 * 5)) % 3 == 0 && (k - (c5 * 5)) % 5 != 0 && (k - (c5 * 5) < 20)) 
        {
            c3 = (k - (c5 * 5)) / 3;
            s += c3 * 3;
        }
    }

    printf("%d %d\n", c5, c3);
    
    return EXIT_SUCCESS;
    
}

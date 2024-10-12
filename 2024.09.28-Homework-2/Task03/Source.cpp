#include <bits/stdc++.h>

int main(int argc, char* argv[])

{
    
    int x1=0, y1=0, r1=0, x2=0, y2=0, r2=0;
    double r;

    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    
    r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    
    if (r1 + r2 >= r && r + r2 >= r1 && r + r1 >= r2)
        printf("YES");
    else
        printf("NO");
        
    return EXIT_SUCCESS;
    
}

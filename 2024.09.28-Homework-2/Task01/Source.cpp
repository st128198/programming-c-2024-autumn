#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) 

{
    
    int x1=0, y1=0, x2=0, y2=0;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
        printf("YES");
    else
        printf("NO");

    return EXIT_SUCCESS;
    
}

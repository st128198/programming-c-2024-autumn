#include <iostream>

int main(int argc, char* argv[])

{
    
    int x=0, y=0, z=0, m=0, n=0, k=0;
    
    scanf("%d %d %d %d %d %d", &x, &y, &z, &m, &n, &k);
    
    if (((x == m) && (y == n) && (z == k)) 
        || ((x == m) && (y == k) && (z == n)) 
        || ((x == n) && (y == k) && (z == m)) 
        || ((x == n) && (y == m) && (z == k)) 
        || ((x == k) && (y == m) && (z == n)) 
        || ((x == k) && (y == n) && (z == m))) 
    {
        printf("Boxes are equal\n");
    }
    else if (((x >= m) && (y >= n) && (z >= k))
        || ((x >= m) && (y >= k) && (z >= n))
        || ((x >= n) && (y >= k) && (z >= m))
        || ((x >= n) && (y >= m) && (z >= k))
        || ((x >= k) && (y >= m) && (z >= n))
        || ((x >= k) && (y >= n) && (z >= m))) 
    {
        printf("The first box is larger than the second one\n");
    }
    else if (((x <= m) && (y <= n) && (z <= k))
        || ((x <= m) && (y <= k) && (z <= n))
        || ((x <= n) && (y <= k) && (z <= m))
        || ((x <= n) && (y <= m) && (z <= k))
        || ((x <= k) && (y <= m) && (z <= n))
        || ((x <= k) && (y <= n) && (z <= m))) {
        printf("The first box is smaller than the second one\n");
    }
    else 
    {
        printf("Boxes are incomparable\n");
    }
    
    return EXIT_SUCCESS;
    
}

#include <iostream>
#include <cmath>

int main(int argc, char* argv[])

{
  
    double k, m, n;
    int result;

    scanf("%lf %lf %lf", &k, &m, &n);
    
    if (k == 0 || m == 0 || n == 0)
    {
        printf("0\n");
        return EXIT_SUCCESS;
    }
    else if (n <= k)
    {
        printf("%.0lf\n", m * 2);
        return EXIT_SUCCESS;
    }
    
    result = static_cast<int>(ceil((n * 2) / k));
    printf("%d\n", result * static_cast<int>(m));
    
    return EXIT_SUCCESS;
  
}

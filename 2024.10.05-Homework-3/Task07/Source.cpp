#include <iostream>

int main() 

{

    long long n = 0;
    long long m = 0;
    std::cin >> n >> m;
    // Нахождение НОД с помощью алгоритма Евклида
    long long a = n;
    long long b = m;
    while (b != 0) 
    {
        long long t = b;
        b = a % b;
        a = t;
    }
    long long g = a;
    long long k = n / g;

    std::cout << k << std::endl;
    return 0;
    
}

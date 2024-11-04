#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> a(100000);
    int n, k = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> a.at(i);
    
    std::cin >> k;
    if (k > 0) k %= n;
    else k = n - ((-k) % n);

    for (int i = n - k; i < n; i++)
        std::cout << a.at(i) << ' ';

    for (int i = 0; i < n - k; i++)
        std::cout << a.at(i) << ' ';

    return 0;
}


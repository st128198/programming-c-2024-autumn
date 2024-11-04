#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> a(100000);
    int n, m = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++) 
    {
        std::cin >> a.at(i);
        if (a.at(i) < a.at(m)) m = i;
    }

    for (int i = m; i < n; i++) std::cout << a.at(i) << ' ';
    for (int i = 0; i < m; i++) std::cout << a.at(i) << ' ';

    return 0;
}

#include <iostream>

int main() 

{
    
    int n = 0;
    std::cin >> n;

    int arr[100];
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }
    
    int x = 0;
    std::cin >> x;

    int p = n + 1; // Изначально Петя встает в конец

    for (int i = 0; i < n; ++i) 
    {
        // Петя встает после всех с равным или большим ростом
        if (arr[i] < x) 
        {
            p = i + 1;
            break;
        }
    }

    std::cout << p << std::endl;

    return 0;
    
}

#include <iostream>
#include <vector>
#include <cmath>

int main() 

{

    int n, x = 0;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> A[i];
    }

    std::cin >> x;

    int closest = A[0];
    int min_diff = abs(A[0] - x);

    // Перебор остальных элементов массива
    for (int i = 1; i < n; ++i) 
    {
        int diff = abs(A[i] - x);
        // Обновляем ближайший элемент, если нашли меньшую разницу
        // или равную разницу, но с меньшим элементом
        if (diff < min_diff || (diff == min_diff && A[i] < closest)) {
            closest = A[i];
            min_diff = diff;
        }
    }
    
    std::cout << closest << std::endl;

    return 0;
    
}

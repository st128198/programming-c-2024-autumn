#include <iostream>
#include <vector>
#include <algorithm> // Для std::max

int main() 

{
    
    int n = 0;
    std::cin >> n;

    std::vector<int> chernichka(n);

    // Ввод количества ягод на каждом кусте
    for (int i = 0; i < n; ++i) 
    
    {
        std::cin >> chernichka[i];
    }

    int max_chernichka = 0;

    // Перебираем все кусты
    for (int i = 0; i < n; ++i) 
    {
        // Индексы соседних кустов
        int l = (i - 1 + n) % n;  // Левый сосед
        int r = (i + 1) % n;     // Правый сосед

        // Считаем сумму ягод с текущего и соседних кустов
        int s = chernichka[l] + chernichka[i] + chernichka[r];

        // Обновляем максимальное количество ягод
        max_chernichka = std::max(max_chernichka, s);
    }

    // Вывод результата
    std::cout << max_chernichka << std::endl;

    return 0;
    
}

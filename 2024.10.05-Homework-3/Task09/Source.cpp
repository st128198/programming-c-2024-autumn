#include <iostream>
#include <set> // Для хранения уникальных корней

int main() 

{

    int a, b, c, d = 0;

    // Ввод коэффициентов уравнения
    std::cin >> a >> b >> c >> d;

    // Множество для хранения уникальных корней
    set<int> roots;

    for (int x = -100; x <= 100; ++x) 
    {
        // Проверяем, является ли x корнем уравнения
        long long value = (long long)a * x * x * x + (long long)b * x * x + (long long)c * x + (long long)d;
        if (value == 0) 
        {
            roots.insert(x); // Добавляем корень в множество
        }
    }

    // Вывод всех уникальных корней в порядке возрастания
    for (int root : roots) 
    {
        std::cout << root << " ";
    }
    std::cout << std::endl;

    return 0;
  
}

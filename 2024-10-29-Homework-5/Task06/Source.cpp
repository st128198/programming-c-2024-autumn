//Это было очень сложно 
//Тут куча всего, но зато сайт больше не пишет TIME LIMIT EXCEEDED 

#include <iostream>
//Вместо сортировки массивов штуку для ускорения 
#include <unordered_set>
#include <vector>

int main() 

{

    std::ios::sync_with_stdio(false); // Отключаем синхронизацию с C для ускорения 
    std::cin.tie(nullptr);            // Отключаем привязку потока ввода-вывода для ускорения 

    // Ввод количества элементов в двух наборах
    size_t n, m = 0;
    std::cin >> n >> m;

    std::unordered_set<int> first_set, second_set;
    std::vector<int> result;

    // Чтение первого набора, без повторений 
    for (size_t i = 0; i < n; ++i) 
    {
        int num = 0;
        std::cin >> num;
        first_set.insert(num);
    }

    // Чтение второго набора, без повторений 
    for (size_t i = 0; i < m; ++i) 
    {
        int num = 0;
        std::cin >> num;
        second_set.insert(num);
    }

    // Находим пересечение
    for (auto num : first_set) 
    {
        if (second_set.count(num)) 
        {
            result.push_back(num);
        }
    }

    // Сортируем результат
    sort(result.begin(), result.end());

    // Выводим результат
    for (auto num : result) 
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
    
}

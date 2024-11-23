#include <iostream>
#include <vector>

class DynamicArray {
private:
    std::vector<int> data; // Используем std::vector для управления динамическим массивом

public:
    // Добавление элемента в конец
    void addToEnd(int value) {
        data.push_back(value);
    }

    // Добавление элемента в начало
    void addToStart(int value) {
        data.insert(data.begin(), value);
    }

    // Удаление элемента с конца
    void removeFromEnd() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            std::cout << "Массив пуст. Не удаётся вернуть из конца.\n";
        }
    }

    // Удаление элемента с начала
    void removeFromStart() {
        if (!data.empty()) {
            data.erase(data.begin());
        } else {
            std::cout << "Массив пуст. Не удаётся вернуть из начала.\n";
        }
    }

    // Вывод массива
    void display() const {
        if (data.empty()) {
            std::cout << "Массив пуст.\n";
            return;
        }

        std::cout << "Элементы массива: ";
        for (const int &value : data) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    DynamicArray array;
    int choice, value;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить в конец\n";
        std::cout << "2. Добавить в начало\n";
        std::cout << "3. Вернуть из конца\n";
        std::cout << "4. Вернуть из начала\n";
        std::cout << "5. Показать элементы массива\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите выбранную опцию: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите элемент для добавления в конец: ";
                std::cin >> value;
                array.addToEnd(value);
                break;
            case 2:
                std::cout << "Введите элемент для добавления в начало: ";
                std::cin >> value;
                array.addToStart(value);
                break;
            case 3:
                array.removeFromEnd();
                break;
            case 4:
                array.removeFromStart();
                break;
            case 5:
                array.display();
                break;
            case 0:
                std::cout << "Выполнено.\n";
                break;
            default:
                std::cout << "Неопределенный выбор. Попробуте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

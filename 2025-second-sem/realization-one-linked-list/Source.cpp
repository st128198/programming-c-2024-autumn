#include <iostream>
using std::cout;
using std::endl;
using std::out_of_range;

template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();
    void push_back(T data);
    void clear();
    int GetSize() 
{ 
  return Size; 
}
    T& operator[](const int index);
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);
    void pop_back();

private:
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node* head;
};

// Конструктор
template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

// Деструктор
template<typename T>
List<T>::~List()
{
    clear();
}

// Удаление первого элемента
template<typename T>
void List<T>::pop_front()
{
    Node* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

// Добавление элемента в конец
template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

// Очистка списка
template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

// Оператор []
template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node* current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }

    // если индекс некорректен — поведение не определено, но можно добавить выброс исключения
    throw out_of_range("Index out of range");
}

// Добавление в начало
template<typename T>
void List<T>::push_front(T data)
{
    head = new Node(data, head);
    Size++;
}

// Вставка по индексу
template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node* newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

// Удаление по индексу
template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

// Удаление последнего
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}

// Тестирование в main
int main()
{

    List<int> lst;
    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(101);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "pop_back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}

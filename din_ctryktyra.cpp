#include <iostream>
#include <locale>
#pragma once

template< typename T > // Описание списка шаблонного типа
class List // Класс списка
{
public:
    List(); // Конструктор списка
    ~List(); // Деструктор списка

    void deleteAll(); // Удаление всего списка
    void deleteFirst(); // Удаление первого элемента
    void pushBack(T data); // Добавление элемента в конец списка
    void pushFront(T data); // Добавление элемента в начало списка
    void insert(T data, int index); // Добавление элемента по указанному индексу
    void remove(T data, int index); // Удаление элемента по указанному индексу

    int getSize(); // Возвращает размер списка
    T& operator[](const int index); // Перегрузка оператора "[]" для удобной индексации к элементу списка

private:
    template< typename T >
    class Node // Класс узла списка
    {
    public:
        Node* pNext; // Указатель на следующий узел
        T data; // Переменная для данных узла

        Node(T data = T(), Node* pNext = nullptr) // Конструктор узла
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size; // Размер списка
    Node<T>* head; // Начало списка
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template< typename T >
List<T>::~List()
{
    deleteAll();
}

template<typename T>
void List<T>::deleteAll()
{
    while (Size)
    {
        deleteFirst();
    }
}

template<typename T>
void List<T>::deleteFirst()
{
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::pushBack(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* curr = this->head;
        while (curr->pNext != nullptr)
        {
            curr = curr->pNext;
        }
        curr->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::pushFront(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        pushFront(data);
    }
    else
    {
        Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->pNext;
        }
        Node<T>* newNode = new Node<T>(data, prev->pNext);
        prev->pNext = newNode;
        Size++;
    }

}

template<typename T>
void List<T>::remove(T data, int index)
{
    if (index == 0)
    {
        deleteFirst();
    }
    else
    {
        Node<T>* prev = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->pNext;
        }
        Node<T>* toDelete = prev->pNext;
        prev->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
int List<T>::getSize()
{
    return Size;
}

template< typename T >
T& List<T>::operator[](const int index)
{
    int count = 0;
    Node<T>* curr = this->head;
    while (curr != nullptr)
    {
        if (count == index)
        {
            return curr->data;
        }
        curr = curr->pNext;
        count++;
    }
}

//................................................................................................//

int main()
{
    setlocale(LC_ALL, "ru");
    List<int> l;
    std::cout << "Заполнение списка:" << std::endl;
    l.pushBack(10);
    l.pushBack(53);
    l.pushBack(34);
    l.pushBack(82);
    l.pushBack(2);

    for (int i = 0; i < l.getSize(); i++)
    {
        std::cout << l[i] << std::endl;
    }

    std::cout << std::endl << "Поиск по индексу \"3\"" << std::endl;
    std::cout << l[3] << std::endl;

    std::cout << std::endl << "Поиск по элемента по значению 34:" << std::endl;
    for (int i = 0; i < l.getSize(); i++)
    {
        if (l[i] == 34)
        {
            std::cout << "Индекс: " << i << " Значение: " << l[i] << std::endl;
        }
    }

    std::cout << std::endl << "Добавление элемента со значением \"1\" по индексу \"2\":" << std::endl;
    l.insert(1, 2);
    for (int i = 0; i < l.getSize(); i++)
    {
        std::cout << l[i] << std::endl;
    }

    std::cout << std::endl << "Удаление элемента со значением \"53\" по индексу \"1\":" << std::endl;
    l.remove(53, 1);
    std::cout << "Удаление элемента в начале списка:" << std::endl;
    l.deleteFirst();
    for (int i = 0; i < l.getSize(); i++)
    {
        std::cout << l[i] << std::endl;
    }

    std::cout << std::endl << "Добавить элемент со значением \"5\" в начало списка:" << std::endl;
    l.pushFront(5);
    std::cout << "Добавить элемент со значением \"130\" в конец списка:" << std::endl;
    l.pushBack(130);
    for (int i = 0; i < l.getSize(); i++)
    {
        std::cout << l[i] << std::endl;
    }

    std::cout << "Удаляем весь список..." << std::endl;
    l.deleteAll();
    if (l.getSize() != 0)
    {
        std::cout << "Ошибка! Список не удален";
    }
    else std::cout << "Успешно!";
    return 0;
}
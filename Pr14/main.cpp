//Var5_Task1
#include <iostream>
#include <ctime>
using namespace std;

struct Node
{
    int data;   // Данные (целое число)
    Node *next; // Указатель на следующий узел
};

int main()
{
    // Шаг 1: Создание динамического списка
    Node *head = nullptr; // Голова списка (пока пустой)
    Node *tail = nullptr; // Хвост списка (пока пустой)

    int n; // Количество элементов в списке
    cout << "Введите количество элементов в списке: ";
    cin >> n;

    cout << "Введите элементы списка:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        // cin >> value;
        value = rand()%10-5;
        cout<<value<<" ";
        // Создаем новый узел
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        // Добавляем узел в конец списка
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Шаг 2: Подсчет количества отрицательных чисел и вычисление произведения
    int negativeCount = 0;
    long long product = 1; // Используем long long для избежания переполнения

    Node *current = head;
    while (current != nullptr)
    {
        if (current->data < 0)
        {
            negativeCount++;
            product *= current->data;
        }
        current = current->next;
    }

    // Шаг 3: Создание динамического массива для отрицательных чисел
    int *negativeArray = new int[negativeCount];

    // Шаг 4: Заполнение массива отрицательными числами из списка
    current = head; // Снова начинаем с головы списка
    int index = 0;
    while (current != nullptr)
    {
        if (current->data < 0)
        {
            negativeArray[index] = current->data;
            index++;
        }
        current = current->next;
    }

    // Шаг 5: Вывод результатов
    if (negativeCount == 0)
    {
        cout << "\nВ списке нет отрицательных чисел.\n";
    }
    else
    {
        cout << "\nПроизведение отрицательных чисел: " << product << endl;
        cout << "Отрицательные числа в массиве: ";
        for (int i = 0; i < negativeCount; i++)
        {
            cout << negativeArray[i] << " ";
        }
        cout << endl;
    }

    // Шаг 6: Освобождение памяти
    // Удаляем список
    current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    // Удаляем массив
    delete[] negativeArray;

    return 0;
}
// Используя динамическую структуру список, подсчитать
//произведение отрицательных чисел в списке.Записать их в
//отдельный динамический массив.Полученный массив вывести
//на экран.

#include <iostream>
#include <cstdlib> // для rand()
#include <ctime>   // для time()
#include <cmath>   // для abs()

using namespace std;

const int MAX_SIZE = 100; // Максимальный размер очереди

struct Queue
{
    int data[MAX_SIZE];
    int last; // Индекс последнего элемента + 1 (размер очереди)
};

// Создание пустой очереди
void Creation(Queue *Q)
{
    Q->last = 0;
}

// Проверка на пустоту
bool Empty(Queue *Q)
{
    return (Q->last == 0);
}

// Проверка на заполненность
bool Full(Queue *Q)
{
    return (Q->last == MAX_SIZE);
}

// Добавление элемента в конец
void Enqueue(Queue *Q, int value)
{
    if (Full(Q))
    {
        cout << "Очередь переполнена!" << endl;
        return;
    }
    Q->data[Q->last++] = value;
}

// Удаление элемента из начала
void Dequeue(Queue *Q)
{
    if (Empty(Q))
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    for (int i = 0; i < Q->last - 1; i++)
    {
        Q->data[i] = Q->data[i + 1];
    }
    Q->last--;
}

// Получение первого элемента
int Front(Queue *Q)
{
    if (Empty(Q))
    {
        cerr << "Очередь пуста!" << endl;
        return -1;
    }
    return Q->data[0];
}

// Вывод очереди
void Print(Queue *Q)
{
    if (Empty(Q))
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    for (int i = 0; i < Q->last; i++)
    {
        cout << Q->data[i] << " ";
    }
    cout << endl;
}

// Вычисление среднего значения
double Average(Queue *Q)
{
    if (Empty(Q))
        return 0.0;
    double sum = 0.0;
    for (int i = 0; i < Q->last; i++)
    {
        sum += Q->data[i];
    }
    return sum / Q->last;
}

// Нахождение ближайшего к среднему элемента
int FindClosestToAverage(Queue *Q, double avg)
{
    if (Empty(Q))
        return 0;
    int closest = Q->data[0];
    double minDiff = abs(Q->data[0] - avg);
    for (int i = 1; i < Q->last; i++)
    {
        double diff = abs(Q->data[i] - avg);
        if (diff < minDiff)
        {
            minDiff = diff;
            closest = Q->data[i];
        }
    }
    return closest;
}

// Перемещение элемента в начало
void MoveClosestToFront(Queue *Q, int closest)
{
    if (Empty(Q) || Q->data[0] == closest)
        return;

    // Находим индекс ближайшего элемента
    int index = -1;
    for (int i = 0; i < Q->last; i++)
    {
        if (Q->data[i] == closest)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        return; // Элемент не найден

    // Сдвигаем элементы вправо, освобождая место для нового первого элемента
    for (int i = index; i > 0; i--)
    {
        Q->data[i] = Q->data[i - 1];
    }
    Q->data[0] = closest;
}

int main()
{
    srand(time(0)); // Инициализация генератора случайных чисел

    Queue Q;
    Creation(&Q);

    int n;
    cout << "Введите количество элементов в очереди (не более " << MAX_SIZE << "): ";
    cin >> n;

    // Заполнение очереди случайными числами от -50 до 50
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 101 - 50; // [-50; 50]
        Enqueue(&Q, num);
    }

    // Вывод исходной очереди
    cout << "\nИсходная очередь: ";
    Print(&Q);

    // Вычисление среднего значения
    double avg = Average(&Q);
    cout << "Среднее значение: " << avg << endl;

    // Нахождение ближайшего элемента
    int closest = FindClosestToAverage(&Q, avg);
    cout << "Ближайший к среднему элемент: " << closest << endl;

    // Перемещение в начало
    MoveClosestToFront(&Q, closest);
    cout << "\nОчередь после перемещения ближайшего элемента в начало:\n";
    Print(&Q);

    return 0;
}

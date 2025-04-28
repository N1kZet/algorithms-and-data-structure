#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    int size;
    Node *first;
    Node *last;
};

void Creation(Queue *Q)
{
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    Q->size = 0;
}

bool Empty(Queue *Q)
{
    return (Q->first == Q->last);
}

void Enqueue(Queue *Q, int value)
{
    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->data = value;
    Q->last->next = NULL;
    Q->size++;
}

void Dequeue(Queue *Q)
{
    if (Empty(Q))
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    Node *temp = Q->first->next;
    Q->first->next = temp->next;
    if (Q->last == temp)
    {
        Q->last = Q->first;
    }
    delete temp;
    Q->size--;
}

void Print(Queue *Q)
{
    if (Empty(Q))
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    Node *current = Q->first->next;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

double Average(Queue *Q)
{
    if (Empty(Q))
        return 0.0;
    double sum = 0.0;
    Node *current = Q->first->next;
    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }
    return sum / Q->size;
}

// Нахождение ближайшего к среднему элемента
int FindClosestToAverage(Queue *Q, double avg)
{
    if (Empty(Q))
        return 0;
    int closest = Q->first->next->data;
    double minDiff = abs(closest - avg);
    Node *current = Q->first->next->next;
    while (current != NULL)
    {
        double diff = abs(current->data - avg);
        if (diff < minDiff)
        {
            minDiff = diff;
            closest = current->data;
        }
        current = current->next;
    }
    return closest;
}

// Перемещение элемента в начало
void MoveClosestToFront(Queue *Q, int closest)
{
    if (Empty(Q) || Q->first->next->data == closest)
        return;

    Node *prev = Q->first;
    Node *current = Q->first->next;

    // Ищем элемент и его предыдущий узел
    while (current != NULL && current->data != closest)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return; // Элемент не найден

    // Переносим в начало
    prev->next = current->next;
    if (current == Q->last)
    {
        Q->last = prev;
    }
    current->next = Q->first->next;
    Q->first->next = current;
}

// Очистка памяти
void Clear(Queue *Q)
{
    while (!Empty(Q))
    {
        Dequeue(Q);
    }
    delete Q->first;
    Q->first = Q->last = NULL;
    Q->size = 0;
}

int main()
{
    srand(time(0)); // Инициализация генератора случайных чисел

    Queue Q;
    Creation(&Q);

    int n;
    cout << "Введите количество элементов в очереди: ";
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

    // Очистка памяти
    Clear(&Q);
    return 0;
}

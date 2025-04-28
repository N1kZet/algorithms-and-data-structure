#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 10;


struct Stack
{
    int data[MAX_SIZE];
    int count;
};

void Creation(Stack *p)
{
    p->count = 0;
}

int Empty(Stack *p)
{
    if (p->count == 0)
        return 1;
    else if (p->count == MAX_SIZE)
        return -1;
    else
        return 0;
}

void Push(Stack *p, int value)
{
    p->data[p->count] = value;
    p->count++;
}

int Pop(Stack *p)
{
    p->count--;
    return p->data[p->count];
}

int Top(Stack *p)
{
    return p->data[p->count - 1];
}

int Size(Stack *p)
{
    return p->count;
}

void PrintStack(Stack *p)
{
    cout << "Стек (верх -> низ): ";
    for (int i = p->count - 1; i >= 0; i--)
    {
        cout << p->data[i] << " ";
    }
    cout << endl;
}

void FillRandomStack(Stack *p)
{
    srand(time(0));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        int num = rand() % 101 - 50;
        Push(p, num);
    }
}

void CreateSecondHalfStack(Stack *original, Stack *newStack)
{
    Stack temp;
    Creation(&temp);

    // Сначала перекидываем все элементы во временный стек
    while (original->count > 0)
    {
        Push(&temp, Pop(original));
    }

    // Теперь возвращаем половину элементов обратно в исходный стек
    int half = temp.count / 2;
    for (int i = 0; i < half; i++)
    {
        Push(original, Pop(&temp));
    }

    // Оставшиеся элементы (вторая половина) помещаем в новый стек
    while (temp.count > 0)
    {
        Push(newStack, Pop(&temp));
    }
}

int main()
{
    Stack s1;
    Creation(&s1);

    FillRandomStack(&s1);

    cout << "Исходный стек:" << endl;
    PrintStack(&s1);

    Stack s2;
    Creation(&s2);

    CreateSecondHalfStack(&s1, &s2);

    cout << "\nСтек из второй половины:" << endl;
    PrintStack(&s2);

    cout << "\nИсходный стек после извлечения второй половины:" << endl;
    PrintStack(&s1);

    return 0;
}

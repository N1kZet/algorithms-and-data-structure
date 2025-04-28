#include <iostream>

using namespace std;
const int n = 6;
struct Queue
{
    int data[n];
    int first;
    int last;
};
void Creation(Queue *Q){
    Q->first = Q->last = 1;
}
bool Full(Queue *Q){
    if (Q->last == Q->first) return true;
    else return false;
}
void Add(Queue *Q){
    int value;
    cout<<"\nЗначение > "; cin>>value;
    if ((Q->last % (n-1) + 1 == Q->first))
        cout<<"\nОчередь заполнена\n\n"; else{
            Q->data[Q->last] = value;
            Q->last = (Q->last % (n-1)) +1;
            cout << "\n" <<"Элемент добавден в очередь \n\n";
        }
}
void Delete(Queue *Q){
    Q->first = (Q->first%(n-1)) + 1;
    cout << "\n" <<"Элемент удален из очереди\n\n";
}
int Top(Queue *Q){
    return Q->data [Q->first];
}
int Size(Queue *Q){
    if (Q->first > Q->last) return (n-1) - (Q->first - Q->last);
    else return Q->last - Q->first;
}

int main(){
    Queue Q;
    Creation(&Q);
    char number;
    do
    {

        cout << "1. Добавить элемент" << "\n";
        cout << "2. Удалить элемент" << "\n";
        cout << "3. Вывести верхний элемент" << "\n";
        cout << "4. Узнать размер очереди" << "\n";
        cout << "0. Выйти\n\n";
        cin >> number;

        switch (number)
        {
        case '1': Add(&Q);
            break;
        //________________________________________
        case '2':
            if (Full(&Q)) cout << "\n" << "Очередь пуста\n\n";
            else Delete(&Q);
            break;
        //________________________________________
        case '3':
            if (Full(&Q)) cout << "\n" << "Очередь пуста\n\n";
            else cout<<"\nНачальный элемент: " << Top(&Q)<<"\n\n";
        break;
        //________________________________________
        case '4':
            if (Full(&Q)) cout << "\n" << "Очередь пустая\n\n";
            else cout << "\nРазмер очереди: " << Size(&Q)<<"\n\n";
        break;
        //________________________________________
        case '0':break;
        default:
            cout<<"\n" << "Команда не найдена.\n\n";
            break;
        }

    } while (number != '0');
     system("pause");
}

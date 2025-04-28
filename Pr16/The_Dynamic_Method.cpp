#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *next;
};
struct Queue{
    int size;
    Node *first;
    Node *last;
};
void Creation(Queue *Q){
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    Q->size = 0;
}
bool Full(Queue *Q){
    if (Q->first == Q->last) return true;
    else return false;
}
int Top(Queue *Q){
    return Q->first->next->data;
}
void Add(Queue *Q){
    int value;
    cout<<"\nЗначение > "; cin>>value;
    Q->last->next = new Node;
    Q->last  = Q->last->next;
    Q->last->data = value;
    Q->last->next = NULL;
    Q->size++;
    cout<<"\nЭлемент добавлен\n\n";
}
void Delete(Queue *Q){
    Q->first = Q->first->next;
    Q->size--;
    cout<<"Элемент удален\n\n";
}
int Size(Queue *Q){
    return Q->size;
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
        case '1':
            Add(&Q);
            break;
        //====================================
        case '2':
            if(Full(&Q)) cout<<"\nОчередь пуста\n\n";
            else Delete(&Q);
        break;
        //====================================
        case '3':
            if (Full(&Q)) cout<<"\nОчередь пуста\n\n";
            else cout<<"\nНачальный элемент: " << Top(&Q) <<"\n\n";
        break;
        //====================================
        case '4':
            if (Full(&Q)) cout<<"\nОчередь пуста\n\n";
            else cout<<"\nРазмер очереди: "<<Size(&Q)<<"\n\n";
        break;
        //====================================
        case '0': break;
        default:
            cout<<"\nКоманда не найдена\n\n";
            break;
        }
    } while (number!='0');
    system("pause");
}

#include <iostream>

using namespace std;
const int n = 4;
struct Queue
{
    int data[n];
    int last;
};
void Creation(Queue *Q){
    Q->last = 0;
}
bool Full(Queue *Q){
    if(Q->last == 0){ return true;}
    else {return false;}
}
void Add(Queue *Q){
    if(Q->last == n){
        cout<<"\nОчередь заполнена\n\n";
    }
    int value;
    cout<<"\nЗначение > "; cin>>value;
    Q->data[Q->last++] = value;
    cout<<endl<<"Элемент добавлен в очередь\n\n";
}
void Delete(Queue *Q){
    for (int i = 0;i<Q->last && i<n;i++){
        Q->data[i]=Q->data[i+1]; Q->last--;
    }
}
int Top(Queue *Q){
    return Q->data[0];
}
int Size(Queue *Q){
    return Q->last;
}
int main(){
    Queue Q;
    Creation(&Q);
    char number;
    do{
        cout<<"1. Добавить элемент"<<"\n";
        cout<<"2. Удалить элемент"<<"\n";
        cout<<"3. Вывести верхний элемент"<<"\n";
        cout<<"4. Узнать размер очереди"<<"\n";
        cout<<"0. Выйти\n\n"; cin>>number;

        switch(number)
        {
            case '1': Add(&Q);
            break;
            //================================================
            case '2':
            if (Full(&Q)) cout << endl <<"Очередь пуста\n\n";
            else{
                Delete(&Q);
                cout<<"\n"<<"Элемент удален из очереди\n\n";
            }break;
            //================================================
            case '4':
            if(Full(&Q)) cout << "\n" << "Очередб пуста\n\n";
            else cout <<"\nРазмер очереди: "<<Size(&Q) << "\n\n";
            break;
            //================================================
            case '3':
                if (Full(&Q)) cout << "\n" << "Очередь пустая\n\n";
                else cout<<"\nНачальный элемент: "<<Top(&Q) << "\n\n";
                break;
            //================================================
            case '0':break;

            default: cout<<"\n"<<"Команда не найдена\n\n";
                break;
            }
    }while(number!='0');
    system("pause");

    return 0;
}












//Создать однонаправленную очередь с числами в диапазоне
//от –50 до + 50. После создания очереди выполнить
//индивидуальное задание.В конце работы
//все очереди должны быть удалены.
// 15.Найти среднее значение всех элементов очереди.Поместить
//ближайший к среднему значению элемент очереди на первую
//позицию.

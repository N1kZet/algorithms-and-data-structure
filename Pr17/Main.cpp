#include <iostream>

using namespace std;

const int n = 3;
struct Stack
{
    int A[n];
    int count;
};
//Создание стека
void Creation(Stack *p){
    p->count = 0;
}
int Empty(Stack *p){
    if (p->count == 0) return 1;
    else if (p->count == n) return -1;
    else return 0;
}
void Add(Stack *p){
    int value;
    cout<<"Введите элемент > "; cin>>value;
    p->A[p->count] = value;
    p->count++;
}
void Delete(Stack *p){
    p->count--;
}
int Top(Stack *p){
    return p->A[p->count-1];
}
int Size(Stack *p){
    return p->count;
}
int main(){
    Stack s;
    Creation(&s);
    char number;
    do{
        cout << "1. Добавить элемент" << "\n";
        cout << "2. Удалить элемент" << "\n";
        cout << "3. Вывести верхний элемент" << "\n";
        cout << "4. Узнать размер стека" << "\n";
        cout << "0. Выйти\n\n";
        cout<<"Номер команды > ";cin >> number;

        switch (number)
        {
        case '1':
            if(Empty(&s) == -1) cout<<"\n"<<"Стек заполнен\n\n";
            else{
                Add(&s);
                cout<<"\nЭлемент добавлен в стек\n\n";
            }
            break;
        case '2':
            if (Empty(&s) == 1) cout << "\nСтек пуст\n\n";
            else {
                Delete(&s);
                cout<<"\nЭелемент удален из стека\n\n";
            }break;
        case '3':
            if (Empty(&s) == 1)
                cout << "\nСтек пуст\n\n";
            else {
                cout<<"\nВерхний элемент: "<<Top(&s) << "\n\n";
            }break;
        case '4':
            if (Empty(&s) == 1)
                cout << "\nСтек пуст\n\n";
            else{
                cout<<"\nРазмер стека: "<<Size(&s) << "\n\n";
            }break;
        case '0':
            break;
        default: cout<<"\nКоманда не найдена\n\n";
            break;
        }
    } while (number != '0');
    system("pause");
}

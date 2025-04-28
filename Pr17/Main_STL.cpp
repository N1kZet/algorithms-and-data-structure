#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <int> S;
    char number;int value;
    do{
        cout << "1. Добавить элемент" << "\n";
        cout << "2. Удалить элемент" << "\n";
        cout << "3. Вывести верхний элемент" << "\n";
        cout << "4. Узнать размер стека" << "\n";
        cout << "0. Выйти\n\n";
        cout << "Номер команды > ";
        cin >> number;
        switch (number)
        {
        case '1':
            cout<<"Значение > ";cin >> value;
            S.push(value);cout<<"\nЭлемент добавленв стек\n\n";
            break;
        case '2':
            if(S.empty() == true) cout<<"\nСтек пуст\n\n";
            else{
                S.pop();cout<<"\nЭлемент удален из стека\n\n";
            }break;
        case '3':
            if (S.empty() == true)
                cout << "\nСтек пуст\n\n";
            else{
                cout<<"\nВерхний элемент стека: " <<S.top()<<"\n\n";
            break;
        case '4':
            if (S.empty() == true)
                cout << "\nСтек пуст\n\n";
            else{
                cout<<"\nРазмер стека: " <<S.size() << "\n\n";
            }break;
        case '0':
            break;
            }
        default:
            cout << "\nКоманда не найдена\n\n";
            break;
        }
    }while (number!='0');
    system("pause");
}

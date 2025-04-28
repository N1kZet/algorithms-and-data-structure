#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    cout << "Введите грудусы: ";
    double a; cin >> a;
    double const pi = 3.1415926535897932384;

    double Ra = (M_PI*a)/180;

    if(1 - sin(3*Ra - pi)!=0){
        double Z = (sin((pi/2) + 3*Ra))/(1 - sin(3*Ra - pi));
        cout << "Результат: " << Z <<"\n";
    }else{
        cout<<"Ошибка ввода"<<"\n";
    }

    return 0;
}

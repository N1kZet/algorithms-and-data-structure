#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    cout << "Введите длину стороны: ";
    double a; cin >>a;
    double const pi = 3.14159265358979323846;
    if (a>0){
        double r = a / 2;

        double S_square = pow(a, 2);
        double S_circle = pi * (pow(r, 2));

        double S = ((S_square - S_circle) * 0.25) + r * r;

        cout << "Площадь равна = " << S << endl;
    }else{
        cout<<"Ошибка ввода"<<"\n";
    }
    return 0;
}

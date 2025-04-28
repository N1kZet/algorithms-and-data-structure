#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double const pi = 3.14159265358979323846;
    int i = 0;
    do{
        cout << "Введите длину стороны: ";
        double a;cin >> a;
        if (a<0){
            i++;
            cout<<"У вас осталось " << 5-i << " попыток"<<"\n";
        }else{
            double r = a / 2;

            double S_square = pow(a, 2);
            double S_circle = pi * (pow(r, 2));

            double S = ((S_square - S_circle) * 0.25) + r * r;

            cout << "Площадь равна = " << S << endl;

            break;
        }
    }while (i<5);

    return 0;
}

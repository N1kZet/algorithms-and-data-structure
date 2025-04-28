#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main(){
    double S,a;
    S = 0.0;
    cout<<"Введите а: ";cin >> a;

    int i = 2;
    while (S<=a)
    {
        S += (1.0/pow(i,2));
        i++;
    }
    cout << "Сумма = " << S << "\n";

}

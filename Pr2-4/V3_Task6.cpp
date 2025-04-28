#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

double arctan(double x, double epsilon)
{
    double sum = 0.0;
    int n = 0;
    double res;

    do
    {
        res = pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
        sum += res;
        n++;
    } while (fabs(res) >= epsilon);

    return sum;
}

int main()
{
    double x1, x2, dx, epsilon = 0.0001;

    cout << "Введите x1: ";
    cin >> x1;
    cout << "Введите x2: ";
    cin >> x2;
    cout << "Введите шаг dx: ";
    cin >> dx;

    cout << "Результаты вычислений arctan(x) на интервале от " << x1 << " до " << x2 << " с шагом " << dx << ":\n";
    double x = x1;
    if ((x1>-1 && x<1) && (x2>-1 && x<1)){
        while (x <= x2)
        {
            cout << "arctan(" << x << ") = " << setprecision(6) << arctan(x, epsilon) << "\n";
            x += dx;

        }
    }else{
        cout<<"Ошибка"<<"\n";
    }

        return 0;
}

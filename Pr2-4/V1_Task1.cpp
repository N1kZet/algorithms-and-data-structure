#include <iostream>
#include <clocale>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    double y, z, a;

    cout << "Введите значение y: ";
    cin >> y;

    if (y < 0)
    {
        z = y * y - 1;
    }
    else if (y >= 0 && y <= 1)
    {
        z = 0;
    }
    else
    {
        z = y * y + 3 * y;
    }

    a = z + 4 * z * z;

    cout << "Значение a = " << a << endl;

    return 0;
}

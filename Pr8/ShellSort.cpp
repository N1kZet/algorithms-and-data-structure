#include <iostream>
#include <ctime>

using namespace std;
int i, j, n, d, c;
void Shell(int A[], int n){
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && A[j] > A[j + d])
            {
                c = A[j];
                A[j] = A[j + d];
                A[j + d] = c;
                j--;
            }
        }
        d = d / 2;
    }
    for (i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Размер массива > ";
    cin >> n;
    int *A = new int[n];
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        A[i] = rand()%100-50;
        cout << A[i] << " ";
    }
    cout << "\nРезультирующий массив: ";
    Shell(A, n);
    delete[] A;
    system("pause>>void");
    return (10);
}

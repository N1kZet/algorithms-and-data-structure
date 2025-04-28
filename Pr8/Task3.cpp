#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>
using namespace std;
int i, j;
double c;
void Shell(double A[], int n)
{
    int d;
    double c;
    d = n / 2;
    int shell_swap = 0;
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
                shell_swap++;
                j--;
            }
        }
        d = d / 2;
    }
    for (i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << A[i] << " ";
    }
    cout << "\nКоличество перестановок: " << shell_swap;
}

void BubleSort(double A[], int n)
{
    int buble_swap = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
            {
                swap(A[i], A[j]);
                buble_swap++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << A[i] << " ";
    }
    cout << "\n\nКоличество перестановок: " << buble_swap;
}
void RandomAdd(double* A, int n){
    for (i = 0; i < n; i++)
    {
        double x = ((double)rand() / RAND_MAX) * 1000.0 - 500.0;
        A[i] = x;
    }
}
void OutputArr(double* A,int n){
    for (int i = 0;i<n;++i){
        cout<<A[i]<<" ";
    }cout<<"\n";
}
void ShellTime(double* arr,int n){
    clock_t start = clock();
    Shell(arr, n);
    clock_t end = clock();
    std::cout << "\nВремя сортировки: " << end - start << " секунд\n";
}
void BubleTime(double* arr, int n){
    clock_t start = clock();
    BubleSort(arr, n);
    clock_t end = clock();
    cout << "\nВремя сортировки: " << end - start << " секунд\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n;
    cout<<"Введите размер массива > ";cin>>n;

    double *A = new double[n];
    RandomAdd(A,n);

    double *a1 = new double[n];
    double *a2 = new double[n];
    for (int i = 0; i < n; i++)
    {
        a1[i] = A[i];
        a2[i] = A[i];
    }

    char number; // Число которое выбирает пользователь
    do
    {
        // cout << "\n\nВведите каким способом отсортироват массив\n"
        cout << "\n1 - Вывод массива\n"
             << "2 - Сортировка Шелла\n"
             << "3 -Пузырьковая сортировка\n"
             << "0 -Exit\n\n ";
        cin >> number;
        switch (number)
        {
        case '1':
            cout << "\nИсходный массив:\n" << endl;
            OutputArr(A, n);
            break;
        case '2':
            cout << "\nОтсортированный массив по Шеллу:" << endl;
            // Shell(a1,n);
            ShellTime(a1,n);
            break;
        case '3':
            cout << "\n\nПузырьковая сортировка:" << endl;
            // BubleSort(a2,n);
            BubleTime(a2,n);
            break;
        case '0':
            cout << "\n\nВыход...\n\n";
            break;
        default:
            cout << "\n\nНеверная команда\n\n";
            break;
        }
    } while (number != '0');
    system("pause");

}


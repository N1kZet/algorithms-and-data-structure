#include <iostream>
#include <ctime>

using namespace std;

void fillingArr(int **arr, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int a;
            cout << "Введите arr[" << i << "][" << j << "] элемент массива: ";
            cin >> a;
            arr[i][j] = a;
        }
    }
}
void randomArr(int **arr, int n, int m)
{
    srand(time(NULL));
    cout << "\nМассив из рандомных чисел: ";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = -100 + rand() % 200;
        }
    }
}
void outputArr(int **arr, int n, int m)
{
    cout << "Массив: \n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}
int summaRow(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 == 0 && arr[i] < 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}
void sortRow(int **arr, int n, int m)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (summaRow(arr[i], m) < summaRow(arr[j], m))
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int FindingNullelement(int **arr, int n, int m)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[j][i] == 0)
            {
                cout << "\nСтолбец с нулевым элементом: ";
                return i + 1;
            }
        }
    }
    cout << "\n";
    cout<<"Нет нулевых элементов.\n";
    return 0;
}


int main()
{
    cout << "Введите размер матрицы NxM: " << "\n";
    int n, m;
    cin >> n;cin >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
    }
    cout << "\nВы хотите сами заполнить массив(y or n): ";
    char s;
    cin >> s;
    switch (s)
    {
    case 'y':
        fillingArr(arr, n, m);
        break;
    case 'n':
        randomArr(arr, n, m);
        break;
    default:
        cout << "\nКоманда не найдена\n\n";
        break;
    }
    outputArr(arr, n, m);
    cout << FindingNullelement(arr, n, m) << "\n";

    sortRow(arr, n, m);
    cout << "\nОтсортированный массив: " << "\n";
    outputArr(arr,n,m);
}

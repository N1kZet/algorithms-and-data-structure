#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void arithmeticMean(int **arr, int n, int m){
    cout << "\n";
    for (int i = 0;i<n;++i){
        double sr = 0;
        for (int j =0;j<m;++j){
            sr+=arr[i][j];
        }
        cout << "Среднее арифметическое строки " << i + 1 << " :" << " ";
        cout << sr/m<<"\n";
    }
}

int main()
{
    cout << "Введите размер матрицы NxM: " << "\n";
    int n;cin>>n;
    int m;cin>>m;
    int **arr = new int *[n];
    for (int j = 0;j<m;++j){
        arr[j] = new int[m];
    }
    srand(time(NULL));

    for (int i =0; i<n; i++){
        for (int j =0;j<m;j++){
            arr[i][j] =rand()%100;
        }
    }
    cout<<"Массив: "<< "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j]<< " ";
        }cout<<"\n";
    }
    arithmeticMean(arr, n, m);
}

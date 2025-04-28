#include <iostream>
#include <ctime>

using namespace std;

void fillingArr(int **arr, int n, int m){
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            int a;
            cout << "Введите arr["<< i <<"]["<<j<<"] элемент массива: ";cin>>a;
            arr[i][j] = a;
        }
    }
}
void randomArr (int **arr, int n, int m){
    srand(time(NULL));
    cout<<"\nМассив из рандомных чисел: ";
    for(int i = 0;i<n;++i){
        for (int j = 0;j<m;++j){
            arr[i][j] =-500+rand()%1000;
        }
    }
}
void outputArr(int **arr, int n,int m){
    cout<<"Массив: \n";
    for (int i = 0;i<n;++i){
        for (int j = 0;j<m;++j){
            cout<<arr[i][j] << "\t";
        }cout<<"\n\n";
    }
}
void arithmeticMean(int **arr, int n, int m)
{
    cout << "\n";
    for (int i = 0; i < n; ++i)
    {
        double sr = 0;
        for (int j = 0; j < m; ++j)
        {
            sr += arr[i][j];
        }
        cout << "Среднее арифметическое строки " << i + 1 << " :" << " ";
        cout << sr / m << "\n";
    }
}

int main(){
    cout<<"Введите размер матрицы NxM: " << "\n";
    int n,m; cin>>n;cin>>m;
    int **arr = new int*[n];
    for (int i=0;i<n;++i){
        arr[i] = new int[m];
    }
    cout<<"\nВы хотите сами заполнить массив(y or n): ";
    char s;cin >> s;
    switch (s)
    {
    case 'y':
        fillingArr(arr, n, m);
        break;
    case 'n':
        randomArr(arr, n, m);
        break;
    default:
        cout<<"\nКоманда не найдена\n\n";
        break;
    }
    outputArr(arr,n,m);
    arithmeticMean(arr,n,m);
}

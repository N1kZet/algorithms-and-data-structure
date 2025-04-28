#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int summaRow(int *arr, int n){
    int sum = 0;
    for (int i=0;i<n;++i){
        if (arr[i]%2 == 0 && arr[i]<0){
            sum+=arr[i];
        }
    }return sum;
}
void sortRow(int **arr, int n, int m){
    for (int i = 0; i<n-1; ++i){
        for (int j = i+1; j<n; ++j){
            if (summaRow(arr[i],m) < summaRow(arr[j],m)){
                swap(arr[i], arr[j]);
            }
        }
    }
}

int FindingNullelement(int **arr, int n,int m){
    for (int i = 0; i<m; ++i){
        for (int j = 0; j<n; ++j){
            if(arr[j][i] == 0){
                cout << "\nСтолбец с нулевым элементом: ";
                return i+1;
            }
        }
    }
    cout << "\n";
    return -1;
}
int main(){
    cout << "Введите размер массива NxM: " << "\n";
    int n;cin >> n;
    int m;cin>>m;
    int **arr = new int *[n];
    for (int i =0; i<m;++i){
        arr[i] = new int[m];
    }
    srand(time(NULL));
    cout << "Массив: " << "\n";
    for (int i = 0; i < n; ++i)
    {
        for(int j=0;j<m;++j)
        {
            arr[i][j] =rand() % 20-10;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout<< FindingNullelement(arr,n,m)<< "\n";

    sortRow(arr,n,m);
    cout<<"\nОтсортированный массив: " << "\n";
    for (int i =0;i<n;++i){
        for(int j =0;j<m;++j){
            cout << arr[i][j] << " ";
        }cout << "\n";
    }
}

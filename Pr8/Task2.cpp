#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int first,last;
void shellSort(int *arr, int n){
    int d = n;
    d = d / 2;
    int c;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                c = arr[j];
                arr[j] =arr[j + d];
                arr[j + d] = c;
                j--;
            }
        }
        d = d / 2;
    }
}

void bubleSort(int *data, int n){
    for (int i = 0; i < n; ++i)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            if (data[i] > data[i + 1])
            {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
    }
}

void quickSort(int *arr, int first, int last){
    int mid, count;
    int f = first, l = last;
    mid = arr[(f + l) / 2];
    do
    {
        while (arr[f] < mid)
            f++;
        while (arr[l] > mid)
            l--;
        if (f <= l)
        {
            count = arr[f];
            arr[f] = arr[l];
            arr[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l)
        quickSort(arr, first, l);
    if (f < last)
        quickSort(arr, f, last);
}


int main(){
    srand(time(NULL));
    cout<<"Введите размер массива: "; int n;cin>>n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    for (int i = 0;i<n;++i){
        arr1[i] = -500 + rand()%1000;
        arr2[i] = -500 + rand() % 1000;
        arr3[i] = -500 + rand() % 1000;
    }cout << "\n\nМассив 1: ";
    for (int i = 0; i<n; ++i){
        cout << arr1[i] << " ";
    }
    cout << "\nМассив 2: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr2[i] << " ";
    }
    cout << "\nМассив 3: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr3[i] << " ";
    }

    bubleSort(arr1,n);
    cout << "\n\nСортировка пузырьком: ";
    for (int i = 0; i<n; ++i){
        cout << arr1[i] << " ";
    }cout<<"\t";

    cout << "\n____________________________________________________________________\n";
    cout << "\nСортировка Шелла: ";
    shellSort(arr2, n);
    for (int i = 0; i < n; ++i)
    {
        cout << arr2[i] << " ";
    }

    cout << "\n____________________________________________________________________\n";
    cout << "\nБыстрая сортировка: ";
    first = 0;last = n-1;
    quickSort(arr3,first,last);
    for (int i = 0; i < n; ++i)
    {
        cout << arr3[i] << " ";
    }
    cout << "\n";
}

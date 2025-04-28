#include <iostream>
#include <clocale>
#include <ctime>
#include <algorithm>

using namespace std;

int min(int arr[], int a){
    int min = arr[0];
    for (int i = 0; i < a; i++)
    {
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int sum(int arr[],int a){
    int firstIndex = -1;
    int lastIndex = -1;

    for (int i = 0; i < a; ++i)
    {
        if (arr[i] >= 0)
        {
            firstIndex = i;
            break;
        }
    }
    for (int i = a - 1; i >= 0; --i)
    {
        if (arr[i] >= 0)
        {
            lastIndex = i;
            break;
        }
    }

    if (firstIndex == -1 || lastIndex == -1 || firstIndex == lastIndex)
    {
        cout<<"Нет положительных чисел"<<"\n";
    }

    int res_sum = 0;
    for (int i = firstIndex + 1; i < lastIndex; ++i)
    {
        res_sum += arr[i];
    }

    return res_sum;
}
void sortArray(int arr[],int a){
    int temp = 0;
    for (int i = 0; i < a - 1; ++i){
        for (int j = 0; j < a - i - 1; ++j) {
            if (arr[j] >= 0 && arr[j + 1] < 0) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    cout << "Введите размер массива: ";
    int a;cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        arr[i] = 0 + rand()%100-50;
    }
    cout << "Массив: ";
    for (int i = 0; i < a; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "---------" << "\n";
    cout << "Минимальное лемент массива: " << min(arr,a) << "\n";
    cout << "Сумма: " << sum(arr,a) << "\n";

    sortArray(arr,a);
    cout << "Сортированный массив: ";
    for (int i = 0; i < a; i++)
    {
        cout <<arr[i]<< " ";
    }cout<<"\n";
}

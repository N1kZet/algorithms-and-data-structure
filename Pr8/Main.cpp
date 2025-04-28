#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
void sortBubleDescending(int arr[], int n)
{
    int temp;
    for(int i = 0;i<n-1;++i){
        for(int j = i+1;j<n;++j){
            if(arr[j]<arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void sortBubleIncreasing(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    cout << "Введите размер массива: "; int n; cin>>n;
    cout << "\nВы хотите сами заполнить массив?(y или n): ";char answer; cin>>answer;
    int arr[n];
    switch (answer)
    {
    case 'y':
        for (int i = 0; i < n; ++i)
        {
            int el;
            cout << "\nВведите " << i + 1 << " элемент массива: ";cin >> el;
            arr[i] = el;
        }
        break;
    case 'n':
        cout << "Напишите диапозон массива от a до b: \n";
        int a;cin >> a;
        int b;cin >> b;
        cout << "Массив в диапозоне от " << a << " до " << b << ": \n\n";
        for (int i = 0; i < n; ++i)
        {
            arr[i] =min(a,b) + rand() % (max(a,b) - min(a,b));
            cout << arr[i] << " ";
        }
        break;
    default:
        cout <<"\nНеверная команда.\n\n";
        return 0;
        break;
    }

    sortBubleDescending(arr, n);
    cout << "\n\nОтсортированный массив по возрастанию(BubleSort): ";
    for (int el : arr)
    {
        cout << el << " ";
    }

    sortBubleIncreasing(arr, n);
    cout << "\n\nОтсортированный массив по убыванию(BubleSort): ";
    for (int el : arr)
    {
        cout << el << " ";
    }cout<<"\n";

}

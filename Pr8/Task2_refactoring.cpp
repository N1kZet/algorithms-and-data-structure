#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;

int first, last;
void shellSort(int *arr, int n)//Сортировка Шелла из Методички
{
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
                arr[j] = arr[j + d];
                arr[j + d] = c;
                j--;
            }
        }
        d = d / 2;
    }
}

void timeSortShell(int *arr, int n)//Просчитываем сколько вермени занимает сортировка
{
    clock_t start = clock();
    shellSort(arr, n);
    clock_t end = clock();
    std::cout << "\nВремя сортировки: " << end - start << " секунд\n";
}

void bubleSort(int *data, int n)//Пузырьковая сортировка
{
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

void timeSortBuble(int *arr, int n) // Просчитываем сколько вермени занимает сортировка
{
    clock_t start = clock();
    bubleSort(arr, n);
    clock_t end = clock();
    cout << "\nВремя сортировки: " << end - start << " секунд\n";
}

void quickSort(int *arr, int first, int last)//Быстрая сортировка
{
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

void timeSortQuickSort(int *arr, int n) // Просчитываем сколько вермени занимает сортировка
{
    first = 0;
    last = n - 1;
    clock_t start = clock();
    quickSort(arr, first, last);
    clock_t end = clock();
    std::cout << "\nВремя сортировки: " << end - start << " секунд\n";
}

void fillingArr(int *arr, int n)//Заполнение массива с клавиатуры
{
    for (int i = 0; i < n; ++i)
    {
        int a;
        cout << "Введите arr[" << i << "] элемент массива: ";
        cin >> a;
        arr[i] = a;
    }
}
void randomArr(int *arr, int n)//Заполнение массива рандомными числами
{
    srand(time(NULL));
    cout << "\n\nМассив из рандомных чисел: \n";
    for (int i = 0; i < n; ++i)
    {
        arr[i] = -100 + rand() % 200;

    }
}
void outputArr(int *arr, int n)//Вывод массива
{
    cout << "\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    srand(time(NULL));
    cout << "Введите размер массива: ";
    int n;cin >> n;
    int arr[n];//основной массив
    cout << "\nВы хотите сами заполнить массив(y or n): ";
    char s;cin >> s;
    switch (s)
    {
    case 'y':
        fillingArr(arr, n);//Функция Заполнение массива с клавиатуры
        break;
    case 'n':
        randomArr(arr, n); //Функция Заполнение массива рандомными числами
        break;
    default:
        cout << "\nКоманда не найдена\n\n";
        return 0;
        break;
    }

    int arr1[n],arr2[n],arr3[n]; //Создаем копию массива arr
    for(int i = 0;i<n;++i){
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }
    outputArr(arr,n);//Выводим массив на экран

    char number;//Число которое выбирает пользователь
    do{
        cout << "\n\nВведите каким способом отсортироват массив\n"
             << "1 - Bubble Sort\n"
             << "2 - Shell Sort\n"
             << "3 -Quick Sort\n"
             << "0 -Exit\n\n ";
        cin >> number;
        switch (number)
        {
        case '1':
            timeSortBuble(arr1,n);//Вызываем функцию чтобы узнать сколько времени занимает сортировка
            cout << "\n\nОтсортированный массив(Bubble Sort): ";
            outputArr(arr1, n);//Выводим отсортированный массив
        break;
        case '2':
            timeSortShell(arr2, n); // Вызываем функцию чтобы узнать сколько времени занимает сортировка
            cout << "\n\nОтсортированный массив(Shell Sort): ";
            outputArr(arr2, n); // Выводим отсортированный массив
            break;
        case '3':
            first = 0;
            last = n - 1;
            timeSortQuickSort(arr3, n); // Вызываем функцию чтобы узнать сколько времени занимает сортировка
            cout << "\n\nОтсортированный массив(Quick Sort): ";
            outputArr(arr3, n); // Выводим отсортированный массив
            break;
        case '0':
            cout<<"\n\nВыход...\n\n";
            break;
        default:
            cout<<"\n\nНеверная команда\n\n";
        break;
        }
    }while(number!='0');
    system("pause");
}

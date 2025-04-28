#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
int c,j,i,d;
int sortShell(int *A, int n){
    int count = 0;
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
        count++;
    }
    return count;
}

int main(){
    ifstream infile("/home/n1kzet/Учеба/Programming-technologies-and-methods/Алгоритмы и структуры данных/Pr10-14/Pr11/input.txt");
    int arr[10];
    if (!infile){
        cout<<"\nОшибка открытия файла";
        return 0;
    }
    for (i = 0; i<10;++i){
        infile>>arr[i];
    }
    infile.close();
    cout<<"\nКоличетсво шагов алгоритма: " << sortShell(arr,10)<<"\n";
    ofstream offline("output.txt");
    for(i=0;i<10;++i){
        offline<<arr[i]<<" ";
    }
    offline.close();
    return 0;

}

//Прочитать из файла одномерный массив из 10 элементов целого типа,
//произвести сортировку Шелла по возрастанию элементов.Результат вывести в
//отдельный файл.На консоль вывести количество шагов алгоритма

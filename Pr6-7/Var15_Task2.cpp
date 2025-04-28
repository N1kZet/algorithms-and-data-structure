#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int proverka(int arr[],int n, int c){
    int count = 0;
    for (int i =0;i<n;i++){
        if (arr[i]>c){
            count++;
        }
    }return count;
}
int proizvedenieAbs(int arr[], int n){
    int pr = 1;
    int max = abs(arr[0]); int maxIndex = 0;    // cout<<"\n";
    for (int i =0; i<n;++i){
        if (abs(max)<abs(arr[i])){
            max = arr[i];
            maxIndex= i;
        }
        // cout<<"Max = " << max << " " << "maxIndex = " << maxIndex<< "\n";
    }
    for (int j = maxIndex+1; j < n; ++j){
        pr*=arr[j];
        // cout << "Pr = " << pr << "\n";
    }return pr;
}
void sortArr(int arr[], int n){
    int temp;
    for (int i = 0;i<n-1;++i){
        for (int j = i+1;j<n;++j){
            if (arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    cout<<"Введите размер массива: ";
    int n; cin>>n;
    int arr[n]; int c = 10;
    srand(time(NULL));
    cout << "\nМассив: ";
    for (int i =0; i<n; i++){
        arr[i] = 0 + rand()%50-25;
        cout << arr[i] << " ";
    }
    cout<<"\nКоличества чисел больших " << c << " :" << proverka(arr,n,c);
    cout<< "\nПроизведение чисел = " << proizvedenieAbs(arr,n);
    sortArr(arr, n);
    cout<< "\nОтсортированный массив: ";
    for (int i = 0; i<n;++i){
        cout<<arr[i] << " ";
    }cout <<"\n";

}

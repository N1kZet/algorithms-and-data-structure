#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    cout<<"Введите размер матрицы: ";
    int N; cin >> N;
    int r[N][N];
    cout << "Матрица " << N << "x" << N << ": " << "\n";
    for (int i = 0; i < N; i++){
        for (int j =0; j<N; j++)
            r[i][j] =0 + rand() %10-5;
    }for(int i =0; i<N;i++){
        for(int j = 0;j<N;j++){
            cout << r[i][j] << " ";
        }
        cout << " " << endl;
    }
}

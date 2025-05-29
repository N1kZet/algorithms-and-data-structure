#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct SYSTEMA
{
    int planetNumber;
    string planetName;
    float diameter;
};

void IzFaila(SYSTEMA* m,int n){
    ifstream in("/home/n1kzet/algorithms-and-data-structure/Pr10-14/Pr13/input.txt");
    if(!in){
        cout<<"Не удалось открыть файл" <<"\n";
        system("pause");
        exit(1);
    }
    for (int i = 0; i<n;++i){
        in >> m[i].planetNumber >> m[i].planetName>> m[i].diameter;
    }
}
void Vivod(SYSTEMA* m, int n){
    ofstream o("Planeta.txt");
    cout<<"Данные занесены в Planeta.txt\n\n";
    for (int i = 0;i<n;++i){
        cout<<"Номер планеты по удалению от Солнца: "<<m[i].planetNumber<<"\n";
        cout<<"Название планеты: " << m[i].planetName<<"\n";
        cout<<"Диаметр: " << m[i].diameter<<"\n";
        cout<<"______________"<<"\n";
        o << "Номер планеты по удалению от Солнца: " << m[i].planetNumber << "\n";
        o << "Название планеты: " << m[i].planetName << "\n";
        o << "Диаметр: " << m[i].diameter << "\n";
        o << "______________" << "\n";
    }
}
int main(){
    int n = 8;
    SYSTEMA* m = new SYSTEMA[n];

    IzFaila(m,n);
    Vivod(m,n);

    delete[] m;
    system("pause");
    return 0;
}

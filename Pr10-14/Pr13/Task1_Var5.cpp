#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Post
{
    string FIO;
    string adress;
    string NameMagazine;
};

void IzFaila(Post *m, int n)
{
    ifstream in("/home/n1kzet/algorithms-and-data-structure/Pr10-14/Pr13/inputs.txt");
    if (!in)
    {
        cout << "Не удалось открыть файл" << "\n";
        system("pause");
        exit(1);
    }
    for (int i = 0; i < n; ++i)
    {
        in >> m[i].FIO >> m[i].adress >> m[i].NameMagazine;
    }
}
void Vivod(Post *m, int n)
{
    ofstream o("Post.txt");
    cout << "Данные занесены в Post.txt\n\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "ФИО: " << m[i].FIO << "\n";
        cout << "Адресс: " << m[i].adress << "\n";
        cout << "Название журнала: " << m[i].NameMagazine << "\n";
        cout << "______________" << "\n";
        o << "ФИО: " << m[i].FIO << "\n";
        o << "Адресс: " << m[i].adress << "\n";
        o << "Название журнала: " << m[i].NameMagazine << "\n";
        o << "______________" << "\n";
    }
}
int main()
{
    int n = 3;
    Post *m = new Post[n];

    IzFaila(m, n);
    Vivod(m, n);

    delete[] m;
    system("pause");
    return 0;
}

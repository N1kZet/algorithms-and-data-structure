#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string filename;
    string newText;
    string fileContent;

    cout<<"Введите путь до файла: ";
    getline(cin,filename);

    ifstream inputFile(filename);
    if(inputFile.is_open()){
        string line;
        while (getline(inputFile,line))
        {
            fileContent+=line + "\n";
        }
        inputFile.close();
        cout << "Файл найден. Текущее содержимое:\n" << fileContent<<"\n";
    }else{
        cout<<"Файл не найден" << "\n";
    }

    cout<<"Введите текст для добавления в файл(Введите 'END' на новой строчке для завершения):\n";
    string temp;
    while (getline(cin,temp) && temp!="END")
    {
        newText += temp+"\n";
    }
    fileContent+=newText;

    ofstream outputFile(filename);
    if(outputFile.is_open()){
        outputFile<<fileContent;
        outputFile.close();
        cout<<"Текст успешно добавлен в файл."<<"\n";
    }else{
        cerr << "Ошибка: не удалось открыть файл для записи." << endl;
        return 1;
    }

    return 0;
}


// Напишите программу, которая считывает текст из текстового
// файла, добавляет к существующему тексту информацию.В необходимо
// проверить наличие текстового файла с заданным именем на диске

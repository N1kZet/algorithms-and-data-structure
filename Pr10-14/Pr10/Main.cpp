#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    cout << "Введите строку: ";
    getline(cin, str);

    int wordCount = 0;
    bool inWord = false;

    for (char c : str)
    {
        if (c == ' ')
        {
            if (inWord)
            {
                wordCount++;
                inWord = false;
            }
        }
        else
        {
            inWord = true;
        }
    }
    if (inWord)
    {
        wordCount++;
    }

    cout << "Количество слов в строке: " << wordCount << endl;

    return 0;
}

// Напишите программу, определяющую число слов в строке.
//Одно слово от другого
//отделяется 1 пробелом.

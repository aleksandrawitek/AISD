#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

//https://docs.microsoft.com/pl-pl/cpp/c-language/arguments-to-main?view=msvc-170

int main(int argc, char *argv[1])
{
    // odpalanie pliku

    ifstream file;
    string file_path = argv[1];
    ifstream input_file(file_path);

    if (!file) 
    {
        cerr << "Unable to open .txt file";
        exit(1);
    }

    // inicjalizacja wektora

    vector<char> file_chars;
    char byte = 0;


    // zapis danych do wektora litera po literze

    while (input_file.get(byte)) 
    {
        file_chars.push_back(byte);
    }

    input_file.close();

    cout << "Plik zawiera: " << endl;

    for (int i =0; i < file_chars.size(); i++)
    {
        cout << file_chars[i] << " ";
    }

    cout << endl;

    // tablica licznikow

    int ile[256]={};

    // zapisanie litery jako ascii

    for (int i =0; i < file_chars.size(); i++)
    {
        int char_ascii = int(file_chars[i]);
        ile[char_ascii] += 1;
    }

    cout << endl;

    // podusmowaie 
    
    for (int i = 0; i <256; i++)
    {
        if(ile[i]!=0)
        {
            cout << "Ilość wystąpień litery '" << char(i) << "' o kodzie ASCII " << i << " jest rowna " << ile[i] << endl;
        }
    }

    




    return 0;
}


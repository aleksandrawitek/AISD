#include <iostream>
#include <vector>
#include <time.h>


using namespace std;

// iloczyn skalarny ze wzory a = [a1,a2] o b =[b1, b2] = a1b1 + a2b2
// dla dwoch wektorow

double scalar(vector <double> a, vector <double> b)
{
    // pomocnicza zmienna

    double scalar_result = 0;

    // warunek na iloczyn skalarny, wektory takich samych wielkosci
    // ilosc mnozen -> n (rozmiar wektora)

    if (a.size() == b.size())
    {
        for(int i = 0; i < a.size(); i++)
        {
            scalar_result += (a[i]*b[i]);
        }
    }

    else
    {
        cout << "Wektory muszą być tego samego rozmiaru! " << endl;
    }

    return scalar_result;

}

int main()
{
    // podpunkt a

    // wektor a,b

    vector <double> a,b;

    int n = 20;

    //inicjalizacja pustego wektora

    for (int i = 0; i < n; i++)
    {
        a.push_back(0);
        b.push_back(0);
    }

    srand (time(NULL));

    for (int i = 0; i < n; i++)
    {
        float x = rand() % 100 + 1;
        a[i] = x;
    }

    for (int i = 0; i < n; i++)
    {
        float x = rand() % 100 + 1;
        b[i] = x;
    }

    //wyswietlenie wektorow

    cout << "Wektor a: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    cout << "Wektor b: ";
    for(int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
    cout << "Iloczyn skalarny: ";
    cout << scalar(a,b) << endl;
    return 0;
}
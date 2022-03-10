#include <iostream>
#include <time.h>
#include <algorithm>
#include <math.h>  

using namespace std;

// n - rozmiar tablicy
// value - wyszukiwana wartość

int find (int array[], int n, int value)
{
    for (int i=0; i < n; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    
    return -1;
}


int main()
{
    srand (time(NULL));

    int n;
    cout << "Proszę podać n z zakresu od 1 do 20" << endl;
    cin >> n;

    // inicjalizacja tablicy

    int array[n];

    for (int i = 0; i < n ; i++)
    {
        // indeksujemy w tablicy od 0 natomiast wartości mamy od 1... n (indeksy od 0 do n-1)

        array[i] = i + 1;
    }

    //pomieszane elementy tablicy
    //https://www.cplusplus.com/reference/algorithm/random_shuffle/

    random_shuffle(array, array + n);

    // szukanie czy dana liczba jest w tablicy

    int value;
    cout << "Jaką liczbę chcesz wyszukać? " << endl;
    cin >> value; 

    int searched =  find(array, n, value);

    if (searched == -1)
    {
        cout << "Nie znaleziono liczby " << value << " w podanej tablicy" << endl;
    }
    else
    {
        cout << "Znaleziono liczbę " << value << " a jej indeks to " << searched  << endl;
    }


    // obliczanie sredniej 

    int sum = 0;
    float avg;

    for (int i = 0; i < n ; i++)
    {
        sum += array[i];    
    }

    avg = sum/n;
    
    cout << "Średnia wynosi  " << avg << endl;

    // obliczanie wariancji

    int sum2 = 0;

    for (int i = 0; i < n ; i++)
    {
        sum2 += pow((array[i]-avg),2);    
    }

    float var = sqrt(sum2/n);

    cout << "Wariancja wynosi " << var << endl;

    return 0;
}
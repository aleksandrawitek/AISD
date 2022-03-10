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
            //ilosc powtorzen ze wzgledu na indeksowanie od 0

            return i+1;
        }
    }
    
    // w naszej wersji nie powinna sie taka sytuacja wydarzyc 

    return -1;
}


int main()
{
    srand (time(NULL));

    // test dla stu tablic 

    int n = 100;

    // pomocnicza tablica trzymajaca ilosc powtorzen

    int repeats[n];

    //przykladowa wielkosc generowanych tablic

    int k = 20;
    // inicjalizacja wlasciwej tablicy
    int array[k];

    for (int i = 0; i < k ; i++)
    {
        // indeksujemy w tablicy od 0 natomiast wartości mamy od 1... n (indeksy od 0 do n-1)
        array[i] = i + 1;
    }

    //pomieszane elementy tablicy
    //https://www.cplusplus.com/reference/algorithm/random_shuffle/
    //oraz wygenerowanie szukanego x

    for (int i = 0; i < n; i++)
    {
        random_shuffle(array, array + k);
        int x = rand() % k + 1; 
        int searched = find(array, k , x);
        repeats[i] = searched;
    }


    // obliczanie sredniej 

    double sum = 0;
    double avg;

    cout << "Dla tablicy o rozmiarze " << k << " oraz " << n << " wykonanych prob: " << endl;

    for (int i = 0; i < n ; i++)
    {
        sum += repeats[i];    
    }

    avg = sum/n;
    
    cout << "Średnia wynosi  " << avg << endl;

    // obliczanie wariancji

    double sum2 = 0;

    for (int i = 0; i < n ; i++)
    {
        sum2 += pow((repeats[i]-avg),2);    
    }

    double var = sqrt(sum2/n);

    cout << "Wariancja wynosi " << var << endl;

    return 0;
}
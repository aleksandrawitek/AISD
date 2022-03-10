#include<iostream>
 
using namespace std;

// n - rozmiar tablicy
// value - wyszukiwana wartość

int search_binary(int array[],int n, int value)
{
    // indeks pierwszego wyrazu tablicy

    int start = 0;

    // indeks drugiego wyrazu tablicy

    int finish = n-1;

    //wykonuj jesli indeks z lewej strony jest mniejszy rowny indeksowi z prawej

    while (start <= finish)
        {
            // srodek tablicy

            int middle = (start+finish)/2;

            // jesli srodkowy wyraz jest rowny wartosci szukanej to znalezlismy nasze rozwiazanie

            if (array[middle] == value)
            {
                return middle;
            }

            // jesli wyraz srodkowy jest wiekszy od szukanej liczby to musimy wybrac zakres o od poczatku do wyrazu przed 
            // srodkowym

            else if (array[middle] > value)
            {
                finish = middle - 1;
            }

            // analogicznie jesli jest mniejszy 

            else if (array[middle] < value)
            {
                start = middle + 1;
            }
        }

    // zwracamy -1 w przypadku kiedy sprawdzilismy wszystkie mozliwosci a nie wyszukano szukanej liczby

    return -1;
}
int main()
{
    // rozmiar tablicy

    int n;
    cout << "Proszę podać n z zakresu od 1 do 20" << endl;
    cin >> n;

    // inicjalizacja tablicy

    int array[n];
    for (int i = 0; i < n ; i++)
    {
        // indeksujemy w tablicy od 0 natomiast wartości mamy od 1... n (indeksy od 0 do n-1)

        array[i] = i + 1;

        // pomocniczo

        // cout << "Element " << i <<": " << array[i] << endl;
    }

    // szukana liczba

    int value;
    cout << "Jaką liczbę chcesz wyszukać? " << endl;
    cin >> value;

    // jesli zwrocone zostanie -1 z funkcji to oznacza, ze liczba nie zostala znaleziona -> nie znajduje sie w tablicy
    // kazda inna liczba od -1 oznacza numer indeksu, na ktorym znajduje sie szukana liczba x 

    int searched =  search_binary(array, n, value);

    if (searched == -1)
    {
        cout << "Nie znaleziono liczby " << value << " w podanej tablicy" << endl;
    }
    else
    {
        cout << "Znaleziono liczbę " << value << " a jej indeks to " << searched  << endl;
    }

    //w ramach przetestowania programu
    
    cout << endl;
    cout << endl;
    cout << "Test na tablicy, ktorej wyrazy nie są o 1 wieksze np [2,4,6,8,10,12,14]" << endl;
    cout << "Wyszukamy w tablicy odpowiednio 3 oraz 8" << endl;
    int array2[7];
    for (int i = 0; i < 7 ; i++)
    {
        array2[i] = (i+1)*2;
    }

    int searched2 =  search_binary(array2, 7, 3);

    if (searched2 == -1)
    {
        cout << "Nie znaleziono liczby 3 " << endl;
    }
    else
    {
        cout << "Znaleziono liczbę 3 a jej indeks to " << searched2  << endl;
    }
    int searched3 =  search_binary(array2, 7, 8);

    if (searched3 == -1)
    {
        cout << "Nie znaleziono liczby 8  w podanej tablicy" << endl;
    }
    else
    {
        cout << "Znaleziono liczbę 8 a jej indeks to " << searched3  << endl;
    }
    

    return 0;
 
}
#include <iostream>
#include <list>
#include <time.h>

using namespace std;

// na podstawie wykladu 2 http://kicia.ift.uni.wroc.pl/notatki/algorytmy/wyklad2/

// struktura elementu listy na dane i wskaźnik do kolejnego elementu

struct lnode
{ 
    int element;

    // wskaznik na nastepny element
    lnode *next;

    // konstruktor
    lnode(int element0, lnode* next0=nullptr):element(element0),next(next0){};

};

// dodawanie elementu z przodu listy
void add(lnode * & L, int new_element)
{
    lnode * x;
    // tworzenie nowego elemetu

    x = new lnode(0,0);

    // inicjalizacja
    // adres nowego elementu	

    x->element = new_element;

    // umieszczamy dane w elemencie
    // następnikiem będzie bieżący pierwszy element listy
    // ustawiamy początek listy na nowy element

    x->next = L;
    L = x;
}
void reverse (lnode * & L)
{
  lnode * x, * y;

  // zapamiętujemy adres pierwszego elementu

  if(L)
  {
    x = L;

    // dopóki istnieje następnik zapamiętanego element zapamiętujemy adres następnika
    // wyjmujemy następnik z listy i wstawiamy go na jej początek
    
    while(x->next)
    {
      y = x->next;
      x->next = y->next;
      y->next = L;
      L = y;
    }
  }
}
void display(lnode *x)
{
    
    // przewijamy wskazniki na nastepne elementy
    while (x)
    {
        // jesli ostatni przejdz do nastepnej linii (ostatni nie wskazuje na nic)
        if (x->next == nullptr)
        {
            cout << x-> element << endl;
        }

        //jesli element nie jest ostatni to oddziel go przecinkiem
        else
        {
            cout << x-> element << ", ";
        }
        x=x->next;
    }
}

 void insertion_sort(lnode *&L)
{

    // sprawdzenie czy lista istnieje i nie jest jedno-elemementowa
    // w przypadku gdy lista jest jedno-elementowa traktujemy ją jako posortowaną

    if (L && L->next)
    {
        // pomocnicza lista do posortowanych elementow

        lnode* sorted = NULL;

        // pomocnicza lista do nieposortowanych elementow

        lnode* unsorted = L;

        // petla trwa dopoki nieposortowana lista nie dojdzie do ostatniego elementu

        while (unsorted)
        {

            // pomocnicza zmienna z aktualnego unsorted

            lnode* value = unsorted;

            // przejscie na nastepna wartosc

            unsorted = unsorted->next;

            // jesli lista jest pusta albo wartosc nieposortowanej jest mniejsza od klucza z posortowanej

            if (!sorted || value->element >= sorted->element) 
            {
                // dodanie elemetu na poczatek posortowanej listy
                value->next = sorted;
                sorted = value;

            } 
            else
            {
                // pomocniczna zmienna do porownywania liczb

                lnode* check = sorted;

                // dopoki nie dojdzie do konca

                while (check)
                {
                    // jesli nastepny klucz obecnej zmiennej nie jest null albo liczba z value jest mniejsza od nastepnego checka

                    if (!check->next || value->element > check->next->element)
                    {
                        // przypisanie do nastepnego value porownywanego checka

                        value->next = check->next;

                        // zamiana miejsc
                        // przypisanie do porownywanego checka = listy value


                        check->next = value;

                        // unikniecie zapętlenia

                        break; 
                    }

                    // przypisujemy check na nastepne miejsce
                    check = check->next;
                }
    
            }
            display(sorted);
        }
        // nadpisanie listy na posortowaną

        L = sorted;
        reverse(L);
    }

}


int main()
{

    srand (time(NULL));

    // stworzenie nowych list
    lnode *L = new lnode(0,0);

    lnode *L2 = new lnode(0,0);

	// dodanie elementow do listy o rozmiarze np 20

    for (int i = 1; i < 11; i++)
    {
        add(L,i); 
    }
    for (int i = 1; i < 11; i++)
    {
        int x = rand() % 100 + 1; 
        add(L2,x); 
    }


    cout << "Początkowa lista:  " << endl;
    display(L);
    cout << endl;
    cout << "Kolejne kroki: " << endl;
    insertion_sort(L);
    cout << "Uporządkowana lista: " << endl;
    cout << endl;
    display(L);
    cout << endl;
    cout << "Drugi przykład z listą nie odwrotną" << endl;
    cout << "Początkowa lista:  " << endl;
    display(L2);
    cout << endl;
    cout << "Kolejne kroki: " << endl; 
    insertion_sort(L2);
    cout << endl;
    cout << "Uporządkowana lista: " << endl;
    display(L2);
    cout << endl;
    
    return 0;
}
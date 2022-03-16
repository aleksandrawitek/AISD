#include <iostream>
#include <time.h>
#include <list>

using namespace std;

// na podstawie wykladu 2 http://kicia.ift.uni.wroc.pl/notatki/algorytmy/wyklad2/

// struktura elementu listy na dane i wskaźnik do kolejnego elementu

struct lnode
{ 
    int key;

    // wskaznik na nastepny element
    lnode *next;

    // konstruktor
    lnode(int key0, lnode* next0=nullptr):key(key0),next(next0){};
};

// podpunkt a
void wypisz(lnode *x)
{
    
    // przewijamy wskazniki na nastepne elementy
    while (x)
    {
        cout << x-> key << " ";
        x=x->next;
    }
}

// podpunkt b

int suma(lnode *x)
{
    int suma = 0;
    // przewijamy wskazniki na nastepne elementy
    while (x)
    {
        suma += (x-> key);
        x=x->next;
    }

    return suma;
}

// podpunkt c
int nty(lnode *x, int n)
{
    int i = 0;
    int result = 0;
    // przewijamy wskazniki na nastepne elementy
    while (x)
    {
        if(i == n)
        {
            result = x-> key;
        }
        x=x->next;
        i++;
    }
    if (i < n)
    {
        result = 0;
    }
    return result;
}

// podpunkt d
// dodawanie elementu z przodu listy
void insert(lnode * & L, int new_key)
{
    lnode * x;
    //tworzenie nowego elemetu

    x = new lnode(0,0);
    //inicjalizacja
    //adres nowego keyu	

    x->key = new_key;

    //umieszczamy dane w elemencie
    //następnikiem będzie bieżący pierwszy element listy
    //ustawiamy początek listy na nowy element

    x->next = L;
    L = x;
} 

// podpunkt e 
// dodanie elementu za mniejszymi

void insert_after_smaller(lnode * & first, int new_key)
{
    //dodaj element aby wydluzyc liste

    insert(first, 0);

    lnode * x;
    int i = 0;

    // zapamiętujemy adres pierwszego elementu
    if(first)
    {
        x = first;

        //podmiana wartosci dopoki nie wieksze

        while(x->next)
        {
            if(x->next->key<=new_key)
            {
                x -> key = x -> next -> key;
                x = x->next;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    x -> key = new_key;
}

// podpunkt f

void remove(lnode *x, int key_remove)
{
	lnode *y = x;
   	while (y->next != nullptr)
   	{
        // musimy mieć wskaźnik do elementu poprzedzającego

		if (y->next->key == key_remove)
		{
            // zapamiętujemy usuwany element

			lnode *removed=y->next;

            // przestawiamy wskaźnik next by omijał usuwany element

			y->next = removed->next; 
            
            // usuwamy z pamięci
			free(removed); 
		} 
		else 
		{
            // idziemy dalej tylko wtedy kiedy nie usuwaliśmy bo nie chcemy zostawić duplikatów
            y = y->next;
		}                            
    }
}

// podpunkt h

void destroy(lnode *&L)
{
    L = nullptr;
}

// podpunkt i

void reverse (lnode * & L)
{
  lnode * x, * y;

  // zapamiętujemy adres pierwszego elementu

  if(L)
  {
    x = L;

    // dopóki istnieje następnik zapamiętanego key zapamiętujemy adres następnika
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


int main()
{
    srand (time(NULL));

    // stworzenie nowej testowej listy
    lnode *L = new lnode(0,0);


	// dodanie keyow do listy o rozmiarze np 20

    for (int i = 0; i < 20; i++)
    {
        int x = rand() % 100 + 1;
        insert(L,x); 
    }

    // usuniecie 0

    remove(L,0);
	
    // podpunkt a
    cout << "a) Pierwotna lista: " << endl;
	wypisz(L);
    cout << endl;
    cout << endl;

    // podpunkt b

    cout << "b) Suma elementow listy: " << suma(L) << endl;
    cout << endl;

    //podpunkt c
    
    int n = rand() % 19;

    //test czy wyjdzie 0
    //int n = 50;

    // n+1 uwzgledniajac indeksowanie od 0

    cout << "c) Nty (liczac od 1) element listy: n - " << n + 1 << " nty element - " << nty(L,n) << endl;
    cout << endl;

    // podpunkt d

    int added = rand() % 100 + 1;
    cout << "d) Dodanie elementu " << added << " na początek listy" << endl;
    cout << "nowa lista: ";
    insert(L,added);
    wypisz(L); 
    cout << endl;
    cout << endl;

    // podpunkt e 

    lnode *pomocniczo = new lnode(0,0);
    int i = 1;
    while (i<40)
    {
        insert(pomocniczo,i);
        i *= 2;
    }

    int y = rand() % 100 + 1;

    cout << "e) Nowa pomocicza lista: " << endl;
    //zeby byly ustawione rosnaco
    reverse(pomocniczo);
    wypisz(pomocniczo);
    cout << endl;
    cout << "Wstawiamy do niej element " << y << endl;
    insert_after_smaller(pomocniczo,y);
    cout << "Lista po wstawieniu: " << endl;
    wypisz(pomocniczo);
    cout << endl;
    cout << endl;

    // podpunkt f

    int to_delete = nty(L,n);
    cout << "f) usuniecie elementu majacego wartosc " << to_delete << " z listy: " << endl;
    wypisz(L);
    cout << endl;
    remove(L,to_delete);
    cout << "Lista po usunieciu: " << endl;
    wypisz(L);
    cout << endl;
    cout << endl;

    // podpunkt g

    cout << "g) brak rozwiazania " << endl;
    cout << endl;

    // podpunkt h

    cout << "h) usunięta lista: " << endl;
    destroy(pomocniczo);
    wypisz(pomocniczo);
    cout << endl;
    cout << endl;

    // podpunkt i

    cout << "Pierwotna lista: " << endl;
    wypisz(L);
    cout << endl;
    cout << "Odwrocona lista: " << endl;
    reverse(L);
    wypisz(L);
    
    return 0;
}
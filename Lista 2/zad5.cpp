#include <iostream>
#include <time.h>
#include <list>

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


//dodawanie elementu z przodu listy
void add(lnode * & L, int new_element)
{
    lnode * x;
    //tworzenie nowego elemetu

    x = new lnode(0,0);

    //inicjalizacja
    //adres nowego elementu	

    x->element = new_element;

    //umieszczamy dane w elemencie
    //następnikiem będzie bieżący pierwszy element listy
    //ustawiamy początek listy na nowy element

    x->next = L;
    L = x;
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

//funkcja remove do usuniecia stale pojawiajacego sie 0 na poczatku

void remove(lnode *x, int element_remove)
{
	lnode *y = x;
   	while (y->next != nullptr)
   	{
        // musimy mieć wskaźnik do elementu poprzedzającego

		if (y->next->element == element_remove)
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



int main()
{
    srand (time(NULL));

    // stworzenie nowych list
    lnode *L = new lnode(0,0);


	// dodanie elementow do listy o rozmiarze np 20

    for (int i = 0; i < 20; i++)
    {
        float x = rand() % 100 + 1;
        add(L,x); 
    }

    // usuniecie 0

    remove(L,0);
	
    cout << "Pierwotna lista: " << endl;
	display(L);

    cout << "Odwrocona lista: " << endl;
    reverse(L);
    display(L);
    
    return 0;
}
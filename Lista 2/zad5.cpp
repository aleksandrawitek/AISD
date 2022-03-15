#include <iostream>
#include <time.h>
#include <list>

using namespace std;

// na podstawie wykladu 2 http://kicia.ift.uni.wroc.pl/notatki/algorytmy/wyklad2/

// struktura elementu listy na dane i wskaźnik do kolejnego elementu

struct node
{ 
    int element;

    // wskaznik na nastepny element
    node *next;

    // konstruktor
    node();
};

// konstruktor

node::node() 
{
    next = nullptr;
}

//dodawanie elementu z przodu listy
void add(node * & first, int new_element)
{
    node * x;
    //tworzenie nowego elemetu

    x = new node;
    //inicjalizacja
    //adres nowego elementu	

    x->element = new_element;

    //umieszczamy dane w elemencie
    //następnikiem będzie bieżący pierwszy element listy
    //ustawiamy początek listy na nowy element

    x->next = first;
    first = x;
} 

void display(node *x)
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

void remove(node *x, int element_remove)
{
	node *y = x;
   	while (y->next != nullptr)
   	{
        // musimy mieć wskaźnik do elementu poprzedzającego

		if (y->next->element == element_remove)
		{
            // zapamiętujemy usuwany element

			node *removed=y->next;

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

void reverse (node * & first)
{
  node * x, * y;

  // zapamiętujemy adres pierwszego elementu

  if(first)
  {
    x = first;

    // dopóki istnieje następnik zapamiętanego element zapamiętujemy adres następnika
    // wyjmujemy następnik z listy i wstawiamy go na jej początek
    
    while(x->next)
    {
      y = x->next;
      x->next = y->next;
      y->next = first;
      first = y;
    }
  }
}



int main()
{
    srand (time(NULL));

    // stworzenie nowej testowej listy
    node *L = new node;


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
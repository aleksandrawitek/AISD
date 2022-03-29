#include <iostream>
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

void insertion_sort(lnode * & L)
{
    //policzenie elementow

    int i = 0;
    int j = 0;
    while(L)
    {
        i++;
        L = L -> next;
    }


    //while (L->next != nullptr)
    //{
        //if(L>L->next)
        //{
         //   cout << L << "> " << L->next << endl;
       // }
      //  L = L -> next;
    //}

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

int main()
{

    // stworzenie nowych list
    lnode *L = new lnode(0,0);


	// dodanie elementow do listy o rozmiarze np 20

    for (int i = 1; i < 21; i++)
    {
        add(L,i); 
    }

    cout << "Początkowa lista:  " << endl;
    display(L);
    cout << endl;
    cout << "Uporządkowana lista: " << endl;
    insertion_sort(L);
    //display(L);

    return 0;
}
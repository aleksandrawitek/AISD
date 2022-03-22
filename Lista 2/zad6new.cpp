#include <iostream>

using namespace std;

struct lnode
{ 
    int element;
    lnode *next;
};

//dodawanie elementu z przodu listy
void add(lnode * & L, int new_element)
{
    lnode * x;
    //tworzenie nowego elemetu

    x = new lnode;
    //inicjalizacja
    //adres nowego elementu	

    x->element = new_element;

    //umieszczamy dane w elemencie
    //następnikiem będzie bieżący pierwszy element listy
    //ustawiamy początek listy na nowy element

    x->next = L;
    L = x;
}
void insert_after_smaller(lnode * & L, int new_element)
{
    //dodaj element aby wydluzyc liste

    add(L, 0);

    lnode * x;
    int i = 0;

    // zapamiętujemy adres pierwszego elementu
    if(L)
    {
        x = L;

        //podmiana wartosci dopoki nie wieksze

        while(x->next)
        {
            if(x->next->element<=new_element)
            {
                x -> element = x -> next -> element;
                x = x->next;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    x -> element = new_element;
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

// funkcja sortowania
// https://pl.wikipedia.org/wiki/Sortowanie_przez_wybieranie
// z listy jest pobierany element o największej wartosci i jest wstawiany na początek
// wykonujemy przechodzac przez wszystkie elemety
// Na zakończenie zmiennej wskazującej początek listy pierwotnej jest przypisywana wartość zmiennej wskazującej na początek listy posortowanej
void sort(lnode *&L)
{ 
    lnode *first_element = nullptr;
    lnode *x, *y, *z;

    // x - wskaźnik na element o maksymalnej wartosci
    // y - wskaźnik na element poprzedzający x lub nullptr, gdy x jest początkowym elementem
    while(L)     
    {
        x = L;
        y = nullptr;
        z = L;
        while(z->next)           
        {
            if (z->next->element>x->element)                
            {
                y = z;
                x = z->next;
            }
            z = z->next;
        }
        if(y)
        {
            y->next = x->next;
        }
        else
        {
            L = x->next;
        }
        x->next = first_element;
        first_element = x;
    }
    L = first_element;
}

// funkcja merge

lnode* merge(lnode* L1, lnode* L2)
{
    // dodaj element z listy 1 i listy 2 do nowej listy
    // przewijamy wskazniki na nastepne elementy
    lnode* result = new lnode;
    lnode *x;
    result = nullptr;

    while (L1)
    {
        // dodaj wszystkie elementy z L1 na poczatek
        add(result,L1-> element);
        L1=L1->next;
    }
    while (L2)
    {
        // dodaj wszystkie elementy z L2 na poczatek
        insert_after_smaller(result,L2-> element);
        L2=L2->next;
    }
    int i = 0;
    int new_element = 0;
    //sort(result);

    return result;
    
}


int main()
{
    srand (time(NULL));

    // stworzenie nowych list
    lnode *L = new lnode;
    lnode *L2 = new lnode;


	// dodanie elementow do listy o rozmiarze np 20

    for (int i = 0; i < 20; i++)
    {
        float x = rand() % 100 + 1;
        add(L,x); 
    }

    for (int i = 0; i < 20; i++)
    {
        float x = rand() % 100 + 1;
        add(L2,x); 
    }

    // usuniecie 0

    remove(L,0);
    remove(L2,0);
	
    cout << "Pierwsza lista: " << endl;
	display(L);
    cout << endl;
    cout << "Druga lista: " << endl;
	display(L2);
    cout << endl;
    cout << "Posortowana pierwsza lista: " << endl;
    sort(L);
	display(L);
    cout << endl;
    cout << "Posortowana druga lista: " << endl;
    sort(L2);
	display(L2);
    cout << endl;
    cout << "Złączone i posortowane listy: " << endl;
    lnode* result = merge(L,L2);
    display(result);
    return 0;
}
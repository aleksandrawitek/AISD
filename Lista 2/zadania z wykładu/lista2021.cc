#include <iostream>
#include <cassert>
#include <memory>


using namespace std;

template <class T> 
class list 
{  /*
      Lista jednokierunkowa 
   */

   struct node 
   {  /*
        Węzeł listy jednokierunkowej
      */

      T key;       // klucz
      node* next;  // adres następnego węzła

      node(T key0,node* next0=nullptr):key(key0),next(next0)
      {  /*
            konstruktor
         */
      }

   }; 

   node *first; // wskaźnik na pierwszy element 
   node **end;  // adres ostatniego nulla (ostatniego next) 

public:   
   
   list():first(nullptr),end(&first)
   {
      /*
         Konstruktor - tworzy pustą listę
      */
   }   
   
   ~list()
   {  /*
         Destruktor  - zwalnia całą pamięć
      */
      while (nonEmpty()) 
         pop_front();
   }

   void put_front(T k)
   {  /*
         Dodaj element na początek listy
      */
      first=new node(k,first);
      if(*end) 
         end=&(*end)->next; // jeśli sit

   }


   void put_back(T k)
   {  /*
         Dodaj element na koniec listy
      */
      *end=new node(k);
      end=&(*end)->next;
   }

   T front()
   {  /*
         Pierwszy element
      */
      return first->key;  
   }

   void pop_front()
   {  /*
         Usuń pierwszy element
      */
      assert(first);
      node* second=first->next; // adres drugiego
      delete first;             // usuń pierwszy element
      first=second;             // teraz drugie będzi pierwszy
      if(!first)
         end=&first;
   }

   T get_front()
   {  /*  
         Usuń i zwróć pierwszy element
      */
      T k=first->key; // zapamiętaj pierwszy klucz
      pop_front();    // usuń pierwszy węzeł 
      return k;       // zwróć wartość jaka w nim była
   }

   bool nonEmpty()
   {
      /*  
         Czy lista jest niepusta ?
      */
      return first;
   }
};



int main()
{ 
   list<int> s;

   // za pomocą put_back() get_front() otrzymujemy implementację kolejki (FIFO)

   for(int i=0;i<=5;i++){
     s.put_back(i);              // Dodajemy elementy  na koniec listy
   }


   while(s.nonEmpty())              // dopóki lista nie jest pusta
      cout<<s.get_front()<<endl;  // wypisujemy i usuwamy elementy z początku listy

   cout<<endl;

   for(int i=0;i<=5;i++){
     s.put_back(i);              // Dodajemy elementy  na koniec listy
   }

   // za pomocą put_front() get_front() otrzymujemy implementację stosu (LIFO)
   for(int i=0;i<=5;i++){
     s.put_front(i);              // Dodajemy elementy na początek listy
   }


   while(s.nonEmpty())              // dopóki lista nie jest pusta
      cout<<s.get_front()<<endl;  // wypisujemy i usuwamy elementy z początku (w kolejności odwrotenej)

   cout<<endl;
}

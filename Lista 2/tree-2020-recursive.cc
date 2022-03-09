#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
using namespace std;

// Operacje na drzewie BST 
// Przykłady do wykładu z Algorytmów i Struktur Danych 
// C. Juszczak (2020)
//                        ┌─8─┐
//                        7   9

struct node  // drzewo BST bez wskaźnika na rodzica
{ 
	int key;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:key(x0), left(l), right(r)
	{}
};

void insert_recursive(node *& t, int x) // wstawianie (rekurenycjnie)
{
	if(!t)
		t=new node(x);
	else
		insert_recursive( x < t->key ? t->left : t->right, x); // tail recursion 
}  

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)  // znajdź wskaźnik na null, gdzie należy podczepić x
		 t1= x < (*t1)->key ?
				&(*t1)->left:
				&(*t1)->right;
	*t1=new node(x);
}  

node* find(node* t,int x)  // wyszukiwanie klucza 
{
	while(t && t->key!=x)
		t=  x < t->key ? 
				t->left : 
				t->right; 
	return t;
}

node** find_recursive(node* &t,int x)  // wyszukiwanie klucza 
{
	if(!t || t->key==x)
		return &t;
	
	if(x < t->key)
		return find_recursive(t->left,x);
	else		
		return find_recursive(t->right,x);
}


void inorder(node *t)  // wypisanie kluczy w porządku "in order"
{
	if(t)
	{
		inorder(t->left);         // wypisze klucze z lewego poddrzewa
		std::cout<<t->key<<" ";   // wypisz klucz z węzła
		inorder(t->right);        // wypisze klucze z lewego poddrzewa
	}
}

void prerder(node *t) // wypisanie kluczy w porządku "pre order"  
{
	if(t)
	{
		std::cout<<t->key<<" ";  // najpierw wypisz klucz z węzła
		prerder(t->left);        // potem z lewego
		prerder(t->right);       // i prawego poddrzewa
	}
}

void postorder(node *t) // wypisanie kluczy w porządku "post order"  
{
	if(t)
	{
		postorder(t->left);        // najpierw wypisz klucze z poddrzew: lewego
		postorder(t->right);       // i prawego
		std::cout<<t->key<<" ";    // a na końcu klucz z węzła 
	}
}

void display(node *t,char z1=' ',char z2=' ') // in order z nawiasami 
{
	if(t)
	{
		std::cout<<z1;
		display(t->left,'(',')');    // lewe poddrzewo w nawiasach okrąłych
		std::cout<<t->key;           // klucz węzła
		display(t->right,'[',']');   // lewe poddrzewo w nawiasach kwadratowych
		std::cout<<z2;
	}
}

void display2(node *t,int d=0) // in order w wiwlu liniach
{
	if(t)
	{
		display2(t->right,d+1);      // prawe poddrewo obócone o 90 stopni w lewo ( wcięcie = d + 1 )
		for(int i=0;i<d;i++)
			std::cout<<"  ";         // klucz z wcięciem d
		std::cout<<t->key<<endl;
		display2(t->left,d+1);       // prawe poddrewo obócone o 90 stopni w lewo ( wcięcie = d + 1 )
	}
}


int n(node* t)   // ilość kluczy w drzewie (rekurencyjnie)
{
	return  t ?  // jeśli drzewo nie jest puste
			1 + n(t->left) + n(t->right): // korzeń + lewe + prawe
			0 ;  // puste drzewo ma 0 kluczy
}

int H(node* t)  // wysokość drzwa BST (rekurencyjnie)
{
	if(!t) return 0;
	int hL=H(t->left);                  // wysokość lewego poddrzewa
	int hR=H(t->right);	                // wysokość prawego poddrzewa
	return 1+ (hR > hL ? hR : hL);      // większa z nich plus jeden 
}

int h(node* t) // wysokość drzwa BST (to samo krócej)
{
	return t ? 
		   1+std::max(h(t->left),h(t->right)):
		   0;
}


int min (node* t)  // minimalny klucz
{
	assert(t);
	while(t->left)
		t=t->left;
	return t->key;
}

int min_recursive (node* t)  // minimalny klucz
{
	assert(t);
	if(t->left)              			   // jeśli jet lewe poddrzewo  
		return min_recursive (t->left);    // to tam jest element najmniejszy
	else								   // a jak nie 
		return t->key;                     // na majminiejszy jest w tym węźle
}


node** leftmost (node*& t)                 // minimalny klucz
{
	assert(t);
	if(t->left)              			   // jeśli jest lewe poddrzewo  
		return leftmost (t->left);         // to tam jest element najmniejszy
	else								   // a jak nie 
		return &t;                         // najminiejszy jest w tym węźle
}

int max (node* t)   // maksymalny klucz
{
	assert(t);
	while(t->right)
		t=t->right;
	return t->key;
}

int max_recursive (node* t)   // maksymalny klucz
{
	assert(t);
	if(t->right)              			   // jeśli jet prawe poddrzewo  
		return max_recursive (t->right);   // to tam jest element majwiększy
	else		              			   // a jak nie
		return t->key;                     // to największ jest tym węźle
}


void remove(node *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	node **t1=&t;
	while (*t1 && (*t1)->key!=x) // znajdź wskaźnik na węzeł zawierający x
		t1= x < (*t1)->key ?
			&(*t1)->left : 
			&(*t1)->right; 

	if(*t1) // jeśli znaleziono 
	{
		if((*t1)->right && (*t1)->left) // jeśli ma dwóch synów
		{                               
			node **t2=&(*t1)->right; // zaczynając od prawego syna
			while ((*t2)->left)      // idź w lewo póki można
				t2=&(*t2)->left;     // docelowo t2 to minimum prawego poddrzewa 
			(*t1)->key=(*t2)->key;   // skopiuj klucz do "usuwanego" węzła 
			t1=t2;                   // i zamiast niego przeznacz ten do usunięcia
		}	
		// tutaj *t1 ma już co najwyżej jednego syna 
		node *son = (*t1)->right ? 
					(*t1)->right : 
					(*t1)->left;
		delete *t1;  // usuwamy węzeł
		*t1=son;     // i zastępujemy synem
	}
}

void remove_recursive(node *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	node **t1=find_recursive(t,x);

	if(*t1) // jeśli znaleziono 
	{
		if((*t1)->right && (*t1)->left) // jeśli ma dwóch synów
		{
		   node ** t2=leftmost((*t1)->right); // znajdź minimum prawego poddrzewa
		   (*t1)->key=(*t2)->key;         // nadpisz jego kluczem usuwany klucz (ten w t1)
		   t1=t2;                         // i przeznacz do usuniecia zamiast (t1)
		}
		// tutaj *t1 ma już co najwyżej jednego syna 
		node *son = (*t1)->right ? 
					(*t1)->right : 
					(*t1)->left;
		delete *t1;  // usuwamy węzeł
		*t1=son;     // i zastępujemy synem
	}
}


void destroy(node*&t) // usunięcie drzwa i zwolnienie pamięci (rekurencyjnie)
{
	if(t)
	{	destroy(t->left);
		destroy(t->right);
		delete t;
		t=nullptr;
	}
}

void prettyLine(node*t, int &n, int level=0)
{   /*
	*/


	if(t)
	{	int k=n;
		prettyLine(t->left,n,level-1);
		stringstream s;
		s <<" "<< t->key<<" ";
		int l=s.str().length();
		n+=l;
		if(level==0)
			cout<<s.str();
		else
			while(l--)
				cout<<" ";
		prettyLine(t->right,n,level-1);
	}
}

void pretty(node*t)
{ 
	/*
		Pokazuje drzewo w terminalu:
	                 7
	             4       9
               3  5     8   10
			 1     6           11 
	*/
  	
	int h=H(t);
	for(int i=0;i<h;i++)
	{
	    int n=0;
		prettyLine(t,n,i);
		cout<<endl;
	}
}

void prettyLine2(node*t, int &n, string c1, string c2, int level=0)
{	
	/*     
		Jedna linia rysunku dla procedurki pretty2
	*/
	if(t)
	{	int k=n;
		prettyLine2(t->left,n," "+c1,"-"+c1,level-1);
		stringstream s;
		s << ' '<<t->key<<' ';
		int l=s.str().length();
		n+=l;
		if(level==0)
			cout<<""<<s.str()<<"";
		else if(level==-1)
		{	
			 for(int i=0;i<(l)/2;i++)
			 	cout<<(c1[0]==' ' ? " " : "─");
			
			cout<<(c1[0]==' ' ? "┌" : "┐");
			 
			   for(int i=(l)/2+1;i<l;i++)
			  	 cout<<(c2[0]==' ' ? " " : "─");
		}
		else 
			for(int i=0;i<l;i++)
			 	cout<< (level>=0 ? " " : c2[-level-1]=='-'?"─":" ");
		prettyLine2(t->right,n,"-"+c2," "+c2,level-1);		 
	}
}

void pretty2(node*t)
{
	/*
		Pokazuje drzewo w terminalu w taki sposób:
	                        ┌──────7────┐
	                    ┌───4─┐     ┌───9───┐
                      ┌─3   ┌─5─┐ ┌─8     ┌─10─┐
					  1     4   6 7       9    11 
	*/
	
	int h=H(t);
	char c=' ';
	for(int i=0;i<h;i++)
	{
	    int n=0;
		prettyLine2(t,n,"","",i); // wyświetl i-tą linię rysunku
		cout<<endl;
	}
}


void interactive(node *&t)
{	int x=0;

	while(cout<<"podaj liczbę ",cin>>x )
	{	if(x<0)
		{
			remove(t,-x);
			cout<< "Usuwam "<<-x<<endl;
		}
		if(x>0)
		{
			insert(t,x);
			cout<< "Dodaję "<<x<<endl;
		}
		if(x==0)
			if(cout<<"Jaką liczbę wyszukać: ",cin >>x)
			{
				pretty(find(t,x));
				cout<<"============================"<<endl;
			}
		pretty2(t);
	}
}

int main(int argc, char* argv[])
{
	node* t=nullptr; // tworzymy puste drzewo BST
	
	// dodajemy klucze
	int liczby[]={20,41,13,32,12,17,4,9,8,200,100,3,8};
	for(int x:liczby)
		insert(t,x);
	cout<<"struktura:\n"; pretty2(t);
	cout<<"kolejność inorder :"; inorder(t); cout<<endl;
	cout<<"kolejność prerder :"; prerder(t); cout<<endl;
	cout<<"kolejność postrder:"; postorder(t);cout<<endl;
	cout<<"Ilość węzłow    = "<<n(t)<<endl;
	cout<<"Wysokość drzewa = "<<h(t)<<endl;
	cout<<"min = "<<min(t)<<" max = "<< max(t)<<endl;
	cout<<"wyszukaj 9: "<<find(t,9)->key<<endl;
	cout<<"usuń korzeń ("<<t->key<<"): \n"; remove_recursive(t,t->key); pretty2(t);
	cout<<"usuń 9:\n"; remove_recursive(t,9); pretty2(t); 
	cout<<"usuń 200:\n"; remove_recursive(t,200); pretty2(t); 
	cout<<"usuń 13:\n"; remove_recursive(t,13); pretty2(t); 

	
	if(argc>1)
		interactive(t);
	destroy(t);
}


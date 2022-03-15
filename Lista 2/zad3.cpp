#include <iostream>
#include <vector>
#include <time.h>


using namespace std;

// iloczyn skalarny ze wzory a = [a1,a2] o b =[b1, b2] = a1b1 + a2b2
// dla dwoch wektorow

double scalar(vector <double> a, vector <double> b)
{
    // pomocnicza zmienna

    double scalar_result = 0;

    // warunek na iloczyn skalarny, wektory takich samych wielkosci
    // ilosc mnozen -> n (rozmiar wektora)

    if (a.size() == b.size())
    {
        for(int i = 0; i < a.size(); i++)
        {
            scalar_result += (a[i]*b[i]);
        }
    }

    else
    {
        cout << "Wektory muszą być tego samego rozmiaru! " << endl;
    }

    return scalar_result;

}

// coefficients - coeff (wspolczynniki)
// n - stopien wielomianu
// x - dla jakiego mamy policzyc
// schemat algorytmu https://pl.wikipedia.org/wiki/Schemat_Hornera

double horner(vector <double> coeff,int n, double x)
{
    // kiedy mamy tylko wyraz wolny, wielomian stopnia 0

	if(n==0)
        return coeff[0];
	
	return x*horner(coeff,n-1,x)+coeff[n];
}

// n - stopien wielomianu a i b

vector <double> vec_multiply(vector<double> vect_a, vector<double> vect_b, int n)
{
    vector<double> vect_c;

    //stopien iloczynu wielomianu jest rowny sumie stopni


    cout << "Stopień wielomianow A(x) i B(x): " << n << endl;
    cout << "Stopień wielomianu C(x) = A(x)B(x): " << 2*n << endl;

    int i,j;

    for (i = 0; i< 2*n +1; i++)
    {
        vect_c.push_back(0);
    }

    for(i=0;i<n+1;i++)
    {
        for (j=0; j < n+1; j++)
        {
            vect_c[i+j] += vect_a[i]*vect_b[j];
        }
    }

    return vect_c;

}



int main()
{
    // podpunkt a

    // wektor a,b

    vector <double> a,b;

    int n = 20;

    //inicjalizacja pustego wektora

    for (int i = 0; i < n; i++)
    {
        a.push_back(0);
        b.push_back(0);
    }

    srand (time(NULL));

    for (int i = 0; i < n; i++)
    {
        double x = rand() % 100 + 1;
        a[i] = x;
    }

    for (int i = 0; i < n; i++)
    {
        double x = rand() % 100 + 1;
        b[i] = x;
    }

    //wyswietlenie wektorow

    cout << "Wektor a: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    cout << "Wektor b: ";
    for(int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
    cout << "Iloczyn skalarny: ";
    cout << scalar(a,b) << endl;

    // podpunt b

    // stopien wielomianu

    int m = 4;

    // inicjalizacja wektora

    vector <double> coeff;  

    for (int i = 0; i < m+1; i++)
    {
        coeff.push_back(0);
    }

    for (int i = 0; i < m+1; i++)
    {
        double x = rand() % 10 + 1;
        coeff[i] = x;
    }

    cout << "Wspolczynniki wielomianu (od lewej a0.. an): ";

    //m+1 bo uwzgledniamy wyraz wolny
    
    for(int i = 0; i < m+1; i++)
    {
        cout << coeff[i] << ' ';
    }

    cout << endl;

    // randomowy x dla ktorego liczymy wartosc wielomianu

    double x = rand() % 10 + 1;

    cout << "X dla ktorego liczymy wartosc wielomianu: " << x << endl;

    cout << "Wartość wielomianu dla x: " << horner(coeff, m, x) << endl;

    // podpunkt c

    // stopien wielomianow

    int o = 4;

    // inicjalizacja wektora

    vector <double> vect_a,vect_b;  

    for (int i = 0; i < o+1; i++)
    {
        vect_a.push_back(0);
        vect_b.push_back(0);
    }

    for (int i = 0; i < o+1; i++)
    {
        double x = rand() % 10 + 1;
        vect_a[i] = x;
    }

    for (int i = 0; i < o+1; i++)
    {
        double x = rand() % 10 + 1;
        vect_b[i] = x;
    }


    cout << "Wspolczynniki wielomianu (od lewej a0.. an) wielomianu A(x): ";

    //m+1 bo uwzgledniamy wyraz wolny
    
    for(int i = 0; i < o+1; i++)
    {
        cout << vect_a[i] << ' ';
    }

    cout << endl;

    cout << "Wspolczynniki wielomianu (od lewej a0.. an) wielomianu B(x): ";

    //m+1 bo uwzgledniamy wyraz wolny
    
    for(int i = 0; i < o+1; i++)
    {
        cout << vect_b[i] << ' ';
    }

    cout << endl;

    cout << "Wspolczynniki wielomianu (od lewej a0.. an) wielomianu C(x)=A(x)B(x): ";

    vector <double> vect_c = vec_multiply(vect_a,vect_b,o);
    
    for(int i = 0; i < 2*o+1; i++)
    {
        cout << vect_c[i] << ' ';
    }

    cout << endl;






    return 0;
}
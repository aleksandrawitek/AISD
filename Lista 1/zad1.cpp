#include <iostream>
using namespace std;

// x^n z rekurencja podpunkt a

float pow_recu(float x, int n)
{
    if (n != 0)
        return (x*pow_recu(x, n-1));
    else
        return 1;
}

// x^n z bez rekurencji podpunkt b

float pow_without_recu(float x, int n)
{
    float result;
    int i = 1;

    if (n != 0)
    {
        if (n % 2 == 0)
        {
            if (n != 2)
            {
                result = 1;

                while (i <= n/2)
                {
                    result *= (x*x);
                    i++;
                }
            }
            else
                return result = x*x;
        }
        else
        {
            result = 1;
            i = 1;
            while (i <= n)
            {
                result *= x;
                i++;
            }
        }
        return result;
    }
    else 
        return 1; 
}

int main()
{
    int n;
    float x;
    
    cout << "Proszę podać x i n." << endl; 
    cout << "x: ";
    cin >> x; 
    cout << endl;
    cout << "n: ";
    cin >> n; 
    cout << endl;
    cout << "Wynik otrzymany za pomocą rekurencji: " << pow_recu(x,n) << endl;
    cout << "Wynik otrzymany bez rekurencji: " << pow_without_recu(x,n) << endl;

}


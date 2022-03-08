#include <iostream>
#define EPS 1e-10

double f(double x){
    return x*x;
}

void bisect(double f0, double f1){
    if (f(f0) * f(f1) > 0 ){
        std::cout << "Funkcja nie ma pierwiastkow w tym przedziale\n";
        return;
    }
    
    double mid = f0;

    while ((f1-f0) >= EPS)
    {
        mid = (f0+f1)/2;
        if (f(mid)==0.0){
            break;
        }
        else if(f(mid) * f(f0) < 0){
            f1 = mid;
        }else{
            f0 = mid;
        }
    }

    std::cout << "Pierwiastka funkcji jest rowna: " << mid <<"\n";
}

int main()
{
    double f0 = -1;
    double f1 = 1;
    bisect(f0, f1);
}
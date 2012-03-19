#include <iostream>

/*program przedstawia sposob dzialania algorytmu szybkiego potegowania
Algorytm szybkiego potęgowania jest konsekwencją obserwacji, że aby obliczyć wartość a^b wystarczy znać a^floor(b/2),
a następnie wykonać jedno lub dwa mnożenia. Np. aby obliczyć 5^175 wystarczy znać wartość x = 5^87,
a następnie policzyć y = x^2 = 5^174 i wynik wynosi =y*5. W ten sposób aby przejść od 5^87 do 5^175 wystarczy wykonać 2 mnożenia zamiast 88, jak wynikałoby to z przytoczonej wyżej definicji.
*/

using namespace std;

long long wynik=0;

long long fast_pot(long long podst, long long wykl, long long mod)
{
    if(wykl==0)
        return 1;
    if(wykl%2==1)
    {
        return (podst*fast_pot(podst, wykl-1, mod))%mod;
    }
    else
    {
        wynik = fast_pot(podst,wykl/2,mod);
        return (wynik*wynik)%mod;;
    }
}

int main()
{
    long long a, b, c, Z;
    cin >> Z;
    for(int i=0; i<Z; i++)
    {
        wynik=0;
        cin >> a >> b >> c;
        cout << fast_pot(a, b, c) << endl;
    }
}



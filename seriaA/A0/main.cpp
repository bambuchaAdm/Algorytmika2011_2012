#include <iostream>
#include <cstdlib>

using namespace std;

int fibb(int n)
{
    int a =0;
    int b=1;
    int c=0;

    for(int i=2;i<=n;i++)
        {
         c=(a+b)%n;     //nie kombinuj, jak sprawe da sie zalatwic w 3 linijkach
         a=b;
         b=c;
        }
    return c%n;
}

int main()
{
    int Z,n;
    cin >> Z;
    for(int i=0;i<Z;i++)
    {
        cin >> n;
        cout << fibb(n) << endl;
    }
    return 0;
}


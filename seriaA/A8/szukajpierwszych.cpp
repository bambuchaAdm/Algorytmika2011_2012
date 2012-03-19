#include <iostream>

using namespace std;

const int MAX = 33000;

bool isprime(int a)
{
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}

int main()
{
    int przedzial=0;
    for(int i=2;i<=MAX;i++)
        if(isprime(i))
        {
            cout << i << ", ";
            przedzial++;
            if(przedzial%1000==0)
                cout << endl;
        }
    cout <<endl << przedzial << endl;
}

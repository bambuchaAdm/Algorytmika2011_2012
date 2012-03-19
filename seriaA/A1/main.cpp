#include <iostream>

using namespace std;

int nwd(unsigned int a, unsigned int b)
{
    unsigned int c=0;
    while(b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main()
{
    int Z=0;
    cin >> Z;
    unsigned int a,b;
    for(int i=0;i<Z;i++)
    {
        cin >> a >> b;
        cout << nwd(a,b) <<endl;
    }
    return 0;
}

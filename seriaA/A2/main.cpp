#include <iostream>
#include <string>

using namespace std;

string dec2bin(int n)
{
    string s=" ";
    if(!n)
        s="0";
    while(n)
    {
        if(!(n%2))  //operator negacji wiąże mocniej - trzeba nawiasów
        {
            s="0"+s;
            n=n/2;
        }
        else
        {
            s="1"+s;
            n=(n-1)/2;
        }
    }
    return s;
}

int main()
{
    int Z, n;
    cin >> Z;
    for(int i=0; i<Z;i++)
    {
        cin >> n;
        cout << dec2bin(n) <<endl;
    }
    return 0;
}

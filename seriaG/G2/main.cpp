/**
*   Author: Adam Piekarczyk
*   Project Title: G2 - Naszyjnik2
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

//#define NDEBUG

using namespace std;

int dlnaszyjnika=0;
bool flaga = true;

vector<int> computePrefixSufix(string s)
{
    vector<int> ps;
    ps.resize(s.size()+1);
    ps[0] = -1;
    int idx = -1; //lazimy tym po wzorcu
    for(int i=1;i<=s.size();i++)
    {
        while(idx > -1 && s[idx] != s[i-1])
            idx = ps[idx];
        idx++;
        ps[i] = idx;
    }
    return ps;
}

void printFalse()
{
    if(flaga)
        cout << "ROZNE" << endl;
}

void printTrue()
{
    if(flaga)
        cout << "IDENTYCZNE" << endl;
    flaga = false;
}

void KMP(string wzo, string tekst, void (*onFound)())
{
    vector<int> ps = computePrefixSufix(wzo);
    #ifndef NDEBUG
    for(int i=0;i<ps.size();i++)
        cout << ps[i] << " ";
    cout << endl;
    #endif
    int idx = 0;
    for(int i=0;i<tekst.size();i++)
    {
        while(idx > 0 && tekst[idx] != tekst[i])
            idx = ps[idx];
        if(wzo[idx]==tekst[i])
            idx++;
        if(wzo.size() == idx)
        {
            onFound();
            idx = ps[idx];
        }
    }
}

string revString(string n)
{
    string wynik;
    for(int i=0;i<n.size();i++)
    {
        wynik = n[i] + wynik;
    }
    return wynik;
}

void readInput()
{
    cin >> dlnaszyjnika;
    string a, b;
    cin >> a >> b;
    a = a + a;
    #ifndef NDEBUG
    cout << a  << endl << b << endl;
    #endif
    KMP(b,a,printTrue);
    b = revString(b);
    #ifndef NDEBUG
    cout << b << endl;
    #endif
    KMP(b,a,printTrue);
    printFalse();
}

void clean()
{
    dlnaszyjnika = 0;
    flaga = true;
}

#ifndef NDEBUG
void test()
{

}
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        readInput();
        #ifndef NDEBUG
        //test();
        #endif
        clean();
    }
}

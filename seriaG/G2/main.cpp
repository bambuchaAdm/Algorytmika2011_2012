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
    ps.resize(s.size());
    ps[0] = 0;
    int idx = 0; //lazimy tym po wzorcu
    for(int i=1;i<s.size();i++)
    {
        while(idx > 0 && s[idx]!=s[i])
            idx = ps[idx];
        if(s[idx]==s[i])
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

void KMP(string wzo, string tekst, void (*onFound)(int))
{
    vector<int> ps = computePrefixSufix(wzo);
    int idx = 0;
    for(int i=0;i<tekst.size()-wzo.size();i++)
    {
        if(wzo[idx]==tekst[i+idx])
            idx++;
        if(idx==wzo.size())
            onFound(i-idx);
        else
        {
            i = i + idx - ps[idx];
            if(idx>0)
                idx = ps[idx];
        }
    }
    cerr << "KMP DONE" << endl;
}

void wywalPozycje(int i)
{
    cout << "ZNALEZIONO NA" << i << endl;
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
    //cin >> dlnaszyjnika;
    string a, b;
    cin >> a >> b;
    KMP(a,b,wywalPozycje);
    /*a = a + a;
    KMP(b,a,printTrue);
    b = revString(b);
    KMP(b,a,printTrue);
    printFalse();*/
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
        test();
        #endif
        clean();
    }
}

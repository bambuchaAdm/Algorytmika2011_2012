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

#define NDEBUG
#define NGENERATE

using namespace std;

int dlnaszyjnika=0;
bool flaga = true;

vector<int> computePrefixSufix(const char *s)
{
    vector<int> ps;
    ps.resize(dlnaszyjnika);
    ps[0] = 0;
    int idx = 0; //lazimy tym po wzorcu
    for(int i=2;i<dlnaszyjnika;i++)
    {
        while(idx > 0 && s[idx]!=s[i])
            idx = ps[idx];
        if(s[idx]==s[i])
            idx++;
        ps[i] = idx;
    }
    #ifndef NDEBUG
    cerr << "PS COMPUTED" << endl;
    #endif
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

void KMP(const char *wzo, const char *tekst, void (*onFound)())
{
    const int DLTEKSTU = dlnaszyjnika * 2;
    vector<int> ps = computePrefixSufix(wzo);
    #ifndef NGENERATE
    for(int i=0;i<ps.size();i++)
        cerr << ps[i] << " ";
    cerr << endl;
    #endif
    int idx = 0;
    for(int i=0;i<DLTEKSTU;i++)
    {
        while(idx>0 && wzo[idx+1]!=tekst[i])
            idx = ps[idx];
        if(wzo[idx+1]==tekst[i])
            idx++;
        if(idx == dlnaszyjnika-1)
        {
            onFound();
            idx = ps[idx];
        }
    }
    #ifndef NDEBUG
    cerr << "KMP DONE" << endl;
    #endif
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
    char a[2000001];
    char b[2000001];
    char revb[2000001];
    cin >> dlnaszyjnika;
    for(int i=0;i<dlnaszyjnika;i++)
    {
        cin >> a[i];
        a[dlnaszyjnika+i] = a[i];
    }
    for(int i=0;i<dlnaszyjnika;i++)
    {
        cin >> b[i];
        revb[dlnaszyjnika-i-1] = b[i];
    }
    KMP(b,a,printTrue);
    #ifndef NDEBUG
    cerr << "KMP 1 DONE" << endl;
    #endif
    //b = revString(b);
    #ifndef NDEBUG
    cerr << "REVERT STRING DONE" << endl;
    #endif
    KMP(revb,a,printTrue);
    #ifndef NDEBUG
    cerr << "KMP 2 DONE" << endl;
    #endif
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
        test();
        #endif
        clean();
    }
}

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
#include <cstring>

#define NDEBUG

using namespace std;

int dlnaszyjnika=0;
bool flaga = false;

bool computePrefixSufix(const char *s)
{
    vector<int> ps;
    ps.resize(dlnaszyjnika);
    ps[0] = 0;
    int idx = 0; //lazimy tym po wzorcu
    for(int i=2;i<dlnaszyjnika;i++)
    {
        while(idx > 0 && s[idx]!=s[i])
        {
            idx = ps[idx];
            if(idx==dlnaszyjnika)
            {
                return true;
            }
        }
        if(s[idx]==s[i])
            idx++;
        if(idx==dlnaszyjnika)
        {
            return true;
        }
        ps[i] = idx;
    }
    return false;
}

void readInput()
{
    char b[3000001];
    char revb[3000001];
    cin >> dlnaszyjnika;
    for(int i=0;i<dlnaszyjnika;i++)
    {
        cin >> b[i];
        revb[dlnaszyjnika-i-1] = b[i];
    }
    b[dlnaszyjnika] = '#';
    revb[dlnaszyjnika] = '#';
    for(int i=0;i<dlnaszyjnika;i++)
    {
        cin >> b[i+dlnaszyjnika+1];
        b[i+2*dlnaszyjnika+1] = revb[i+dlnaszyjnika+1] = b[i+dlnaszyjnika+1];
        revb[i+2*dlnaszyjnika+1] = revb[i+dlnaszyjnika+1];
    }
    flaga = computePrefixSufix(b);
    if(flaga)
        cout << "IDENTYCZNE" << endl;
    else
    {
        if(computePrefixSufix(revb))
            cout << "IDENTYCZNE" << endl;
        else
            cout << "ROZNE" << endl;
    }
}

void clean()
{
    dlnaszyjnika = 0;
    flaga = false;
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

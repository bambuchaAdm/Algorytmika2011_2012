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
    return ps;
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

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

using namespace std;

int dlnaszyjnika=0;
bool flaga = false;
vector<int> ps;

bool computePrefixSufix(string s)
{
    ps[0] = -1;
    int idx = -1; //lazimy tym po wzorcu
    for(int i=1;i<=s.size();i++)
    {
        while(idx > -1 && s[idx] != s[i-1])
            idx = ps[idx];
        idx++;
        ps[i] = idx;
        if(ps[i] == dlnaszyjnika)
            return true;
    }
    return false;
}

void readInput()
{
    flaga = false;
    cin >> dlnaszyjnika;
    ps.resize(dlnaszyjnika+10);
    string a, b;
    cin >> a >> b;
    string temp = a + '#' + b + b;
    flaga = computePrefixSufix(temp);
    for(int i=0;i<dlnaszyjnika;i++)
    {temp = a[dlnaszyjnika-1-i];
    if(!flaga)
        flaga = computePrefixSufix(temp);}
    if(flaga)
        cout <<"IDENTYCZNE" << endl;
    else
        cout << "ROZNE" << endl;
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
    }
}

/**
*   Author: Adam Piekarczyk
*   Project Title: G1 - Hymn
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
**/

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define NDEBUG

using namespace std;

#ifndef NDEBUG
void test(vector<int> t, int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
        cout << t[i] << " ";
    cout << endl;
}
#endif

int minPeriod(string s)
{
    vector<int> ps; //ps - tablica prefikso-sufiksowa
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
    #ifndef NDEBUG
    test(ps,s.size());
    #endif
    if(s.size()%(s.size()-ps[s.size()])==0)
        return s.size()/(s.size() - ps[s.size()]);
    else
        return 1;
}

void readInput()
{
    string slowo;
    cin >> slowo;
    cout << minPeriod(slowo) << endl;
}

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

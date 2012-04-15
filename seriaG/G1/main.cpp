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
void test(const int *t, int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
        cout << t[i] << " ";
    cout << endl;
}
#endif

int minPeriod(const char *s)
{
    int *ps = new int[strlen(s) + 1]; //ps - tablica prefikso-sufiksowa
    ps[0] = -1;
    ps[1] = 0;
    int idx = 0; //lazimy tym po wzorcu
    for(int i=2; s[i]; i++)
    {
        while(idx > 0 && s[idx+1] != s[i])
            idx = ps[idx];
        if(s[idx+1]==s[i])
            idx++;
        ps[i] = idx;
    }
    #ifndef NDEBUG
    test(ps,strlen(s));
    #endif
    return strlen(s)/(strlen(s) - ps[strlen(s)-1]-1);
}

void readInput()
{
    string slowo;
    cin >> slowo;
    cout << minPeriod(slowo.c_str()) << endl;
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

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

bool KMP(const char *wzo, const char *tekst, bool (*onFound)())
{

}

void readInput()
{
    cin >> dlnaszyjnika;

}

void printFalse()
{
    cout << "ROZNE" << endl;
}

bool printTrue()
{
    cout << "IDENTYCZNE" << endl;
    return false;
}

void clean()
{
    dlnaszyjnika = 0;
}

#ifndef NDEBUG
void test()
{

}
#endif

int main()
{
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

/**
*   Author: Adam Piekarczyk
*   Project Title: D10 - Naszyjnik
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
**/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int lkoral;

vector<vector<char> > naszyjnik;
vector<vector<bool> > ok;

void readInput()
{
    scanf("%d",&lkoral);
    naszyjnik.resize(lkoral+1,vector<char>(2));
    for(int i=1;i<=lkoral;i++)
    {
        scanf("%c %c",&naszyjnik[i][0],&naszyjnik[i][1]);
    }
    naszyjnik[0][0] = naszyjnik[lkoral][0];
    naszyjnik[0][1] = naszyjnik[lkoral][1];
}

void printOutput()
{

}

void clean()
{

}

void test()
{

}

int main()
{
    int z;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        readInput();

        printOutput();
        //test();
        clean();
    }
}

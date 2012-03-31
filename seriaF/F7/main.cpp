/**
*   Author: Adam Piekarczyk
*   Project Title:
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

enum strona
{
    IMP = 1,
    REB = 2
};

int dlx, dly, dlz;
int lmiesiecy;

vector< vector< vector<strona > > > galaktyka;

void readInput()
{
    scanf("%d %d %d %d",&dlx,&dly,&dlz,&lmiesiecy);
    galaktyka.resize(dlx);    //ciekawe czy to sie da rozszerzyc odpowiednio uzywajac jednej templatki?
    for(int i=0;i<dlx;i++)
    {
        galaktyka[i].resize(dly,vector<strona>(dlz,REB));
    }
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
        #ifndef NDEBUG
        test();
        #endif
        clean();
    }
}

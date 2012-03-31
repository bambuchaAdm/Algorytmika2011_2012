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
int lSkladowychImp;

vector< vector< vector<strona > > > galaktyka;
vector< vector<int> > wojna;
vector<int> parent;

void readInput()
{
    scanf("%d %d %d %d",&dlx,&dly,&dlz,&lmiesiecy);
    const int MAXSEKTOROW = dlx*dly*dlz;
    parent.resize(MAXSEKTOROW);
    for(int i=0;i<MAXSEKTOROW;i++)
    {
        parent[i] = i;
    }
    galaktyka.resize(dlx);    //ciekawe czy to sie da rozszerzyc odpowiednio uzywajac jednej templatki?
    for(int i=0;i<dlx;i++)
    {
        galaktyka[i].resize(dly,vector<strona>(dlz,REB));
    }
    wojna.resize(lmiesiecy);
    for(int i=0;i<lmiesiecy;i++)
    {
        int lsektorow;
        scanf("%d",&lsektorow);
        wojna[i].resize(lsektorow);
        for(int j=0;j<lsektorow;j++)
        {
            scanf("%d",&wojna[i][j]);
        }
    }
}

int findRoot(int n)
{
    if(parent[n]!=n)
    {
        parent[n] = findRoot(parent[n]);
    }
    return parent[n];
}

void printOutput(int x, int y)
{
    xRoot = findRoot(x);
    yRoot = findRoot(y);
    if(xRoot != yRoot)
    {

    }
}

void clean()
{
    wojna.clear();
    galaktyka.clear();
    paren.clear();
    lSkladowychImp = 0;
}

#ifndef NDEBUG
void test()
{

}
#endif

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

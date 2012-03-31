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
    IMP,
    REB
};

int dlx, dly, dlz;
int lmiesiecy;
int lSkladowychImp;
int lmiesNieSpoj;

vector<strona> galaktyka;
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
    galaktyka.resize(MAXSEKTOROW,REB);
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

void unionImp(int x, int y)
{
    xRoot = findRoot(x);
    yRoot = findRoot(y);
    if(xRoot != yRoot)
    {
        lSkladowychImp--;
        parent[xRoot]=yRoot;
    }
}

/*
*   Ogólnie rzecz biorąc, mamy 6 sąsiadów. Koordynaty, zakładając że x to obecna planeta:
*   -po lewej - x + dlx
*
*/
void sprawdzSasiadow(int n)
{
    if(galaktyka[n+dlx]==IMP)
    {
        unionImp(n,n+dlx);
    }
}

void symuluj()
{
    for(vector<int>::iterator it=wojna.rbegin();it!=wojna.rend();it++)
    {
        for(int i=0;i<*it.size();i++)
        {
            galaktyka[*it[i]] = IMP;
            lSkladowychImp++;

        }
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
        symuluj();
        printOutput();
        #ifndef NDEBUG
        test();
        #endif
        clean();
    }
}

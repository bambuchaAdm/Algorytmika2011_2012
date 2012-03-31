/**
*   Author: Adam Piekarczyk
*   Project Title: F7 - Imperium
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

//#define NDEBUG

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
    int xRoot = findRoot(x);
    int yRoot = findRoot(y);
    if(xRoot != yRoot)
    {
        lSkladowychImp--;
        parent[xRoot]=yRoot;
    }
}

/*
*   Ogólnie rzecz biorąc, mamy 6 sąsiadów. Koordynaty, zakładając że x to obecna planeta:
*   -po lewej - x + dlx
*   -po prawej - x - dlx
*   -w przód - x + 1
*   -w tyl - x - 1
*   -do góry - x + dlx*dly
*   -w dół - x - dlx*dly
*/
void sprawdzSasiadow(int n)
{
    const int MAXSYSTEM = dlx*dly*dlz-1;
    if(n+dlx <= MAXSYSTEM)
        if(galaktyka[n+dlx]==IMP)
        {
            unionImp(n,n+dlx);
        }
    if(n-dlx >= 0)
        if(galaktyka[n-dlx]==IMP)
        {
            unionImp(n,n-dlx);
        }
    if(n+1 <= MAXSYSTEM)
        if(galaktyka[n+1]==IMP)
        {
            unionImp(n,n+1);
        }
    if(n-1 >= 0)
        if(galaktyka[n-1]==IMP)
        {
            unionImp(n,n-1);
        }
    const int SKOK = dlx*dly;
    if(n+SKOK <= MAXSYSTEM)
        if(galaktyka[n+SKOK]==IMP)
        {
            unionImp(n,n+SKOK);
        }
    if(n-SKOK >= 0)
        if(galaktyka[n-SKOK]==IMP)
        {
            unionImp(n,n-SKOK);
        }
}

void symuluj()
{
    /*for(vector< vector<strona> >::reverse_iterator it=wojna.rbegin();it!=wojna.rend();it++) //dostaje jakieś dzikie błędy z STL-a i jest za późno na to, żebym kminił o co chodzi.
    {
        for(int i=0;i<(*it).size();i++)
        {
            galaktyka[((*it)[i])] = IMP;
            lSkladowychImp++;
            sprawdzSasiadow(((*it)[i]));
        }
        if(lSkladowychImp!=0)
            lmiesNieSpoj++;
    }*/
    for(int j=wojna.size()-1;j>=0;j--)
    {
        for(int i=0;i<wojna[j].size();i++)
        {
            galaktyka[wojna[j][i]] = IMP;
            lSkladowychImp++;
            sprawdzSasiadow(wojna[j][i]);
        }
        if(lSkladowychImp!=0)
            lmiesNieSpoj++;
    }
}

void clean()
{
    wojna.clear();
    galaktyka.clear();
    parent.clear();
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
        cout << lmiesNieSpoj << endl;
        #ifndef NDEBUG
        test();
        #endif
        clean();
    }
}

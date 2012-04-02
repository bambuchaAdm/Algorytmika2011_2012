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

#define NDEBUG

using namespace std;

enum strona
{
    IMP,
    REB
};

int dlx, dly, dlz;
int lmiesiecy;
int lSkladowychImp = 0;
int lmiesNieSpoj = 0;
int krok[3] = {1};

vector<strona> galaktyka;
vector< vector<int> > wojna;
vector<int> parent;

void readInput()
{
    scanf("%d %d %d %d",&dlx,&dly,&dlz,&lmiesiecy);
    const int MAXSEKTOROW = dlx*dly*dlz;
    krok[1] = dlx;
    krok[2] = dlx*dly;
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
    /*for(int i = 0 ; i < 3 ; ++i)
    {
	if(n + krok[i] <= MAXSYSTEM)
	    if(galaktyka[n+krok[i]]==IMP)
	    {
		unionImp(n,n+krok[i]);
	    }
	if(n - krok[i] >= 0)
	    if(galaktyka[n-krok[i]]==IMP)
	    {
		unionImp(n,n-krok[i]);
	    }
    }*/ //jednak to bardziej skomplikowane.
    if(n+dlx <= MAXSYSTEM)
        if(galaktyka[n+dlx]==IMP && n%(dlx*dly) < dlx*dly - dlx)
        {
            unionImp(n,n+dlx);
        }
    if(n-dlx >= 0)
        if(galaktyka[n-dlx]==IMP && n%(dlx*dly) >= dlx)
        {
            unionImp(n,n-dlx);
        }
    if(n+1 <= MAXSYSTEM)
        if(galaktyka[n+1]==IMP && ((n%(dlx*dly))%dlx) != dlx-1)
        {
            unionImp(n,n+1);
        }
    if(n-1 >= 0)
        if(galaktyka[n-1]==IMP && ((n%(dlx*dly))%dlx) != 0)
        {
            unionImp(n,n-1);
        }
    const int SKOK = dlx*dly;
    if(n+SKOK <= MAXSYSTEM)
        if(galaktyka[n+SKOK]==IMP && n < (dlz-1)*SKOK)
        {
            unionImp(n,n+SKOK);
        }
    if(n-SKOK >= 0)
        if(galaktyka[n-SKOK]==IMP && n >= SKOK)
        {
            unionImp(n,n-SKOK);
        }
}

void symuluj()
{
    typedef vector< vector<int> >::reverse_iterator riter;
    typedef vector<int>::iterator iter;
    for(riter it=wojna.rbegin() ; it != wojna.rend() ; it++)
    {
        for(iter i = it->begin() ; i != it->end() ; ++i)
        {
            galaktyka[*i] = IMP;
            lSkladowychImp++;
            sprawdzSasiadow(*i);
        }
        if(lSkladowychImp>1)
            lmiesNieSpoj++;
    }
}

void clean()
{
    wojna.clear();
    galaktyka.clear();
    parent.clear();
    lSkladowychImp = 0;
    lmiesNieSpoj = 0;
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

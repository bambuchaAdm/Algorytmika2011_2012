/**
*   Author: Adam Piekarczyk
*   Project Title: F8 - Zasilanie
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

#define NDEBUG

using namespace std;


enum Direction
{
    X,
    Y,
    Z
};

struct Kabel
{
    int ID;
    int x;
    int y;
    int z;
    char znak;

    int getDirection(Direction direction)
    {
        switch(direction)
        {
        case X:
            return x;
        case Y:
            return y;
        case Z:
            return z;
        }
    }
};

bool compareZ( const Kabel & a,const Kabel & b)
{
    return a.z < b.z;
}

bool compareY(const Kabel & a,const Kabel & b)
{
    return a.y < b.y;
}

bool compareX(const Kabel & a,const Kabel & b)
{
    return a.x < b.x;
}

typedef bool (* Comparer)(const Kabel & a, const Kabel & b);

Comparer dim(Direction direction)
{
    switch(direction)
    {
        case X:
            return &compareX;
        case Y:
            return &compareY;
        case Z:
            return &compareZ;
    }
}


int dlx,dly,dlz; //wymiary prostokata
int lkabli;

vector<Kabel> kable;
vector<int> parent;


#ifndef NDEBUG
void test()
{
    for(int i=0; i<parent.size();i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
}
#endif

void readInput()
{
    cin >> dlx >> dly >> dlz >> lkabli;
    const int MAX = lkabli+1000;
    kable.resize(MAX);
    parent.resize(MAX);
    for(int i=0;i<lkabli;i++)
    {
        parent[i] = i;
        kable[i].ID = i;
        cin >> kable[i].x >> kable[i].y >> kable[i].z >> kable[i].znak;
    }
}

void clean()
{
    parent.clear();
    kable.clear();
}

int Find(int x)
{
    if(parent[x]!=x)
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void unionBiegun(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if(xRoot != yRoot)
        parent[xRoot] = yRoot;
}

void przegladaj(Direction a,Direction b,Direction c)
{
    vector<Kabel> kable1 = kable;
    sort(kable1.begin(), kable1.end(), dim(a));
    int idxp = 0;
    int idxk = 0;
    for(int i=0;i<=dlz;i++)
    {
        bool isB = false;
        bool isC = false;
        while(kable1[idxk].getDirection(a) == i)
        {
            if(kable1[idxk].getDirection(b) == 0)
                isB = true;
            if(kable1[idxk].getDirection(c) == 0)
                isC = true;
            idxk++;
        }
        if(isB && isC)
        {
            for(int i=idxp; i<idxk-1;i++)
            {
                unionBiegun(kable1[i].ID,kable1[i+1].ID);
            }
        }
        idxp = idxk;
    }

}

// Z, X, Y
// Y, Z, X
// X, Z ,Y
bool szukajOdpowiedzi()
{
    vector<char> znakss;
    const char NIC = '#';
    znakss.resize(lkabli,NIC);
    for(int i=0;i<parent.size();i++)
    {
        if(znakss[parent[i]] == NIC)
            znakss[parent[i]] = kable[i].znak;
        if(znakss[parent[i]] == '0')
            znakss[parent[i]] = kable[i].znak;
        if((znakss[parent[i]] == '+') && (kable[i].znak == '-'))
            return true;
        if(znakss[parent[i]] == '-' && kable[i].znak == '+')
            return true;
    }
    return false;
}

void laczKable()
{
    przegladaj(Z,X,Y);
    przegladaj(Y,Z,X);
    przegladaj(X,Z,Y);
    if(szukajOdpowiedzi())
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        readInput();
        laczKable();
        #ifndef NDEBUG
        test();
        #endif
        clean();
    }
}

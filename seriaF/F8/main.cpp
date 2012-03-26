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

enum Biegun         //why nie pyka?
{
    PLUS = (char) '+',
    MINUS = (char) '-',
    BRAK = (char) 0
};

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

bool compareZ(// const Kabel & a,const Kabel & b)
// {
//     return a.z < b.z;
// }

// bool compareY(const Kabel & a,const Kabel & b) 
// {
//     return a.y < b.y;
// }

// bool compareX(const Kabel & a,const Kabel & b) 
// {
//     return a.x < b.x;
// }
typedef bool (* Comparer)(const Kabel & a, const Kabel & b);
int dlx,dly,dlz; //wymiary prostokata
int lkabli;

vector<Kabel> kable;
vector<int> parent;

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


void test()
{
    /*for(int i=0; i<kable.size();i++)
    {
        cout << kable[i].x << " " << kable[i].y << " " << kable[i].z << " " << kable[i].znak << endl;
    }*/
    for(int i=0; i<parent.size();i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
}

void readInput()
{
    cin >> dlx >> dly >> dlz >> lkabli;
    const int MAX = lkabli;
    kable.resize(MAX);
    parent.resize(MAX);
    for(int i=0;i<lkabli;i++)
    {
        parent[i] = i;
        kable[i].ID = i;
        cin >> kable[i].x >> kable[i].y >> kable[i].z >> kable[i].znak;
    }
}

void printOutput()
{

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

void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if(xRoot != yRoot)
        parent[xRoot] = yRoot;
}

void przegladajZ()
{
    vector<Kabel> kable1 = kable;
    kable1.resize(lkabli);
    sort(kable1.begin(), kable1.end(), compareZ);
    int idxp = 0;
    int idxk = 0;
    for(int i=0;i<=dlz;i++)
    {
        bool isX = false;
        bool isY = false;
        while(kable1[idxk].z == i)
        {
            if(kable1[idxk].x == 0)
                isX = true;
            if(kable1[idxk].y == 0)
                isY = true;
            idxk++;
        }
        if(isY && isX)
        {
            for(int i=idxp; i<idxk-1;i++)
            {
                Union(kable1[i].ID,kable1[i+1].ID);
            }
        }
        idxp = idxk;
    }

}

void przegladajY()
{
    vector<Kabel> kable1 = kable;
    kable1.resize(lkabli);
    sort(kable1.begin(), kable1.end(), compareY);
    int idxp = 0;
    int idxk = 0;
    for(int i=0;i<=dly;i++)
    {
        bool isX = false;
        bool isZ = false;
        while(kable1[idxk].y == i)
        {
            if(kable1[idxk].z == 0)
                isZ = true;
            if(kable1[idxk].x == 0)
                isX = true;
            idxk++;
        }
        if(isZ && isX)
        {
            for(int i=idxp; i<idxk-1;i++)
            {
                Union(kable1[i].ID,kable1[i+1].ID);
            }
        }
        idxp = idxk;
    }

}

void przegladajX()
{
    vector<Kabel> kable1 = kable;
    kable1.resize(lkabli);
    sort(kable1.begin(), kable1.end(), compareX);
    int idxp = 0;
    int idxk = 0;
    for(int i=0;i<=dlx;i++)
    {
        bool isZ = false;
        bool isY = false;
        while(kable1[idxk].x == i)
        {
            if(kable1[idxk].z == 0)
                isZ = true;
            if(kable1[idxk].y == 0)
                isY = true;
            idxk++;
        }
        if(isY && isZ)
        {
            for(int i=idxp; i<idxk-1;i++)
            {
                Union(kable1[i].ID,kable1[i+1].ID);
            }
        }
        idxp = idxk;
    }

}

bool szukajOdpowiedzi()
{
    for(int i=0;i<parent.size();i++)
    {

    }
    return false;
}

void laczKable()
{
    przegladajZ();
    przegladajX();
    przegladajY();
    szukajOdpowiedzi();
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
        printOutput();
        assert(true);
        test();
        clean();
    }
}

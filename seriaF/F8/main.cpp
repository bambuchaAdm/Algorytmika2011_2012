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

struct kabel
{
    int ID;
    int x;
    int y;
    int z;
    char znak;
};

int dlx,dly,dlz; //wymiary prostokata
int lkabli;

vector<kabel> kable;
vector<int> parent;

bool compareZ(kabel const & a, kabel const & b)
{
    return a.z < b.z;
}

bool compareY(kabel const & a, kabel const & b)
{
    return a.y < b.y;
}

bool compareX(kabel const & a, kabel const & b)
{
    return a.x < b.x;
}

void test()
{
    for(int i=0; i<kable.size();i++)
    {
        cout << kable[i].x << " " << kable[i].y << " " << kable[i].z << " " << kable[i].znak << endl;
    }
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
        parent[x] = Find(parent[x]);
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
    sort(kable.begin(), kable.end(), compareZ);

}

void laczKable()
{
    przegladajZ();
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
        test();
        clean();
    }
}

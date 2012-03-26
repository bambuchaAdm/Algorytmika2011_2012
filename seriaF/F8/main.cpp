/**
*   Author: Adam Piekarczyk
*   Project Title: F8 - Zasilanie
*   School Year: 2011/2012
*   School: VLO Krak�w
*   Class: 1e
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

#define NDEBUG

using namespace std;

enum biegun         //why nie pyka?
{
    PLUS = (char) '+',
    MINUS = (char) '-',
    BRAK = (char) 0
};

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
    vector<kabel> kable1 = kable;
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
    vector<kabel> kable1 = kable;
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
    vector<kabel> kable1 = kable;
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

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

#define NDEBUG

using namespace std;

struct kabel
{
    int x;
    int y;
    int z;
    char znak;
}

int dlx,dly,dlz; //wymiary prostokata
int lkabli;

vector<kabel> kable;

bool compareZ(kabel a, kable b)
{
    return a.z < b.z;
}

bool compareY(kabel a, kable b)
{
    return a.y < b.y;
}

bool compareX(kabel a, kable b)
{
    return a.x < b.x;
}

void readInput()
{
    cin >> x >> y >> z;
    cin >> lkabli;
    const int MAX = lkabli;
    kable.resize(MAX);
    for(int i=0;i<lkabli;i++)
    {
        cin >> kable[i].x >> kable[i].y >> kable[i].z >> kable[i].znak;
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
    ios_base::sync_with_stdio(false);
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

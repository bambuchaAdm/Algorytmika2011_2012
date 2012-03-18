/**
*   Author: Adam Piekarczyk
*   Project Title: D10 - Naszyjnik
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
**/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int lkoral;

vector<vector<char> > naszyjnik;
vector<vector<bool> > ok;

void readInput()
{
    scanf("%d",&lkoral);
    const int MAX = lkoral+1;
    naszyjnik.resize(MAX,vector<char>(2));
    ok.resize(MAX,vector<bool>(2,false)); //ciekawe czy to dziala
    for(int i=1;i<=lkoral;i++)
    {
        //scanf("%c %c",&naszyjnik[i][0],&naszyjnik[i][1]);     //czemu to nie dziala? Zapytac kogos.
        cin >> naszyjnik[i][0] >> naszyjnik[i][1];
    }
    naszyjnik[0][0] = naszyjnik[lkoral][0];
    naszyjnik[0][1] = naszyjnik[lkoral][1];
}

void printOutput(bool war)
{
    if(war)
    {
        for(int i=1;i<=lkoral;i++)
        {
            if(ok[i][0])
                printf("%c ",naszyjnik[i][0]);
            else
                printf("%c ",naszyjnik[i][1]);
        }
        printf("\n");
    }
    else
    {
        printf("-\n");
    }
}

void clean()
{
    naszyjnik.clear();
    ok.clear();
}

void test()
{
    for(int i=0;i<=lkoral;i++)
        cout << ok[i][0];
    cout << endl;
    for(int i=0;i<=lkoral;i++)
        cout << ok[i][1];
    cout << endl;
}

void test1()
{
    for(int i=0;i<=lkoral;i++)
        cout << naszyjnik[i][0] << " " << naszyjnik[i][1] << endl;
}

bool ukladajKorale(bool a, bool b)
{
    ok[0][0] = a;
    ok[0][1] = b;
    for(int i=1;i<=lkoral;i++)
    {
        for(int j=0;j<2;j++)
        {
            ok[i][j] = (ok[i-1][0] && naszyjnik[i][j] != naszyjnik[i-1][0]) || (ok[i-1][1] && naszyjnik[i][j] != naszyjnik[i-1][1]);
        }
    }
    if(ok[lkoral][0] || ok[lkoral][1])
        return true;
    return false;
}

int main()
{
    int z;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        readInput();
        test1();/*
        if(ukladajKorale(true,false))
        {
            test();
            printOutput(true);
            clean();
            continue;
        }
        else if(ukladajKorale(false,true))
        {
            test();
            printOutput(true);
            clean();
            continue;
        }
        test();
        printOutput(false);
        clean();*/
    }
    return 0;
}

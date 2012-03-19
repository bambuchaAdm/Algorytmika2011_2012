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
#include <stack>

using namespace std;

int lkoral;

vector<vector<char> > naszyjnik;
vector<vector<bool> > ok;
vector<vector<int> > skad;

void readInput()
{
    scanf("%d",&lkoral);
    const int MAX = lkoral+1;
    naszyjnik.resize(MAX,vector<char>(2));
    skad.resize(MAX,vector<int>(2));
    ok.resize(MAX,vector<bool>(2,false)); //ciekawe czy to dziala
    for(int i=1;i<=lkoral;i++)
    {
        //scanf("%c %c",&naszyjnik[i][0],&naszyjnik[i][1]);     //czemu to nie dziala? Zapytac kogos.
        cin >> naszyjnik[i][0] >> naszyjnik[i][1];
    }
    naszyjnik[0][0] = naszyjnik[lkoral][0];
    naszyjnik[0][1] = naszyjnik[lkoral][1];
}

void printOutput()
{
    stack<char> S;
    if(ok[lkoral][0])
    {
        int poprz = 0;
        S.push(naszyjnik[lkoral][0]);
        for(int i=lkoral;i>1;i--)
        {
            S.push(naszyjnik[i-1][skad[i][poprz]]);
            poprz = skad[i][poprz];
        }
    }
    else
    {
        int poprz = 1;
        S.push(naszyjnik[lkoral][1]);
        for(int i=lkoral;i>1;i--)
        {
            S.push(naszyjnik[i-1][skad[i][poprz]]);
            poprz = skad[i][poprz];
        }
    }
    while(!S.empty())
    {
        cout << S.top();
        S.pop();
    }
    cout << endl;
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
            if(ok[i-1][0] && naszyjnik[i][j] != naszyjnik[i-1][0])
            {
                ok[i][j] = true;
                skad[i][j] = 0;
            }
            else if(ok[i-1][1] && naszyjnik[i][j] != naszyjnik[i-1][1])
            {
                ok[i][j] = true;
                skad[i][j] = 1;
            }
        }
        if((!ok[i][0]) && (!ok[i][1]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int z;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        readInput();
        //test1();
        if(ukladajKorale(true,false))
        {
            //test();
            printOutput();
            clean();
            continue;
        }
        else if(ukladajKorale(false,true))
        {
            //test();
            printOutput();
            clean();
            continue;
        }
        cout << "-" << endl;
    }
    return 0;
}

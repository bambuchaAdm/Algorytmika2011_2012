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
bool isPossible = false;

vector<vector<char> > naszyjnik;
vector<vector<bool> > ok;
vector<vector<int> > skad;

void readInput()
{
    scanf("%d",&lkoral);
    const int MAX = lkoral+1;
    naszyjnik.resize(MAX,vector<char>(2));
    skad.resize(MAX,vector<int>(2));
    ok.resize(MAX,vector<bool>(2,false));
    for(int i=0;i<lkoral;i++)
    {
        //scanf("%c %c",&naszyjnik[i][0],&naszyjnik[i][1]);     //czemu to nie dziala? Zapytac kogos.
        cin >> naszyjnik[i][0] >> naszyjnik[i][1];
    }
    naszyjnik[lkoral][0] = naszyjnik[0][0];
    naszyjnik[lkoral][1] = naszyjnik[0][1];
}

void printOutput(int strona)
{
    if(isPossible)
        return;
    isPossible = true;
    stack<char> S;
    strona = skad[lkoral][strona];
    //cout << lkoral - 1 << strona << endl;
    //cout << naszyjnik[lkoral-1][strona] << endl << endl;
    S.push(naszyjnik[lkoral-1][strona]);
    for(int i=lkoral-1; i>0; i--)
    {
        strona = skad[i][strona];
       // cout << naszyjnik[i-1][strona] << endl;
        S.push(naszyjnik[i-1][strona]);
       // cout << strona << endl;
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
    isPossible = false;
    naszyjnik.clear();
    ok.clear();
    skad.clear();
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

void ukladajKorale()
{
    for(int i=1;i<lkoral;i++)
    {
        if(ok[i][0])
        {
            if(naszyjnik[i][0]!=naszyjnik[i+1][0])
            {
                ok[i+1][0] = true;
                skad[i+1][0] = 0;
            }
            if(naszyjnik[i][0]!=naszyjnik[i+1][1])
            {
                ok[i+1][1] = true;
                skad[i+1][1] = 0;
            }
        }
        if(ok[i][1])
        {
            if(naszyjnik[i][1]!=naszyjnik[i+1][0])
            {
                ok[i+1][0] = true;
                skad[i+1][0] = 1;
            }
            if(naszyjnik[i][1]!=naszyjnik[i+1][1])
            {
                ok[i+1][1] = true;
                skad[i+1][1] = 1;
            }
        }
    }
}

int main()
{
    int z;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        readInput();
        isPossible=false;
        bool czyToMaSens = false;
        if(naszyjnik[0][0]!=naszyjnik[1][0])
        {
            ok[1][0] = true;
            skad[1][0] = 0;
            czyToMaSens = true;
        }
        if(naszyjnik[0][0]!=naszyjnik[1][1])
        {
            ok[1][1] = true;
            skad[1][1] = 0;
            czyToMaSens = true;
        }
        if(czyToMaSens)
        {
            ukladajKorale();
            if(ok[lkoral][0] && ok[0][0])
                printOutput(0);
        }
        isPossible = false;
        ok.clear();
        skad.clear();
        const int MAX = lkoral +1;
        skad.resize(MAX,vector<int>(2));
        ok.resize(MAX,vector<bool>(2,false));
        if(isPossible)
        {
            if(naszyjnik[0][1]!=naszyjnik[1][0])
            {
                ok[1][0]=true;
                skad[1][0] = 1;
            }
            if(naszyjnik[0][1]!=naszyjnik[1][1])
            {
                ok[1][1] = true;
                skad[1][1] = 1;
            }
            ukladajKorale();
            if(ok[lkoral][1] && ok[0][1])
                printOutput(1);
        }
        if(!isPossible)
            cout << "-" << endl;

    }
    return 0;
}

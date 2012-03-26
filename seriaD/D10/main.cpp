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

int n, flaga;
vector<char> naszyjnik;
vector<bool> ok;
vector<int> skad;
/*char naszyjnik[1000005][2];
bool ok[1000005][2];
int skad [1000005][2];
*/
void ukladajKorale (int i)
{
       if(ok[i][0]==true)
       {

            if(naszyjnik[i][0]!=naszyjnik[i+1][0])
            {
                ok[i+1][0]=true;
                skad[i+1][0]=0;
            }
            if(naszyjnik[i][0]!=naszyjnik[i+1][1])
            {
                ok[i+1][1]=true;
                skad[i+1][1]=0;
            }
       }
       if(ok[i][1]==true)
       {
            if(naszyjnik[i][1]!=naszyjnik[i+1][0])
            {
                ok[i+1][0]=true;
                skad[i+1][0]=1;
            }
            if(naszyjnik[i][1]!=naszyjnik[i+1][1])
            {
                ok[i+1][1]=true;
                skad[i+1][1]=1;
            }
       }
}

void wypisz(int x)
{
    if(flaga==1)
        return;
    flaga=1;
    stack<char> s;
    x=skad[n][x];
    s.push(naszyjnik[n-1][x]);
    for(int i=n-1; i>0; i--)
    {
        x=skad[i][x];
        s.push(naszyjnik[i-1][x]);
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

void clean()
{
    for(int i=0; i<=n; i++)
    {
        ok[i][0]=false;
        ok[i][1]=false;
    }
}

void readInput()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin>>naszyjnik[i][0] >> naszyjnik[i][1];
    naszyjnik[n][0]=naszyjnik[0][0];
    naszyjnik[n][1]=naszyjnik[0][1];
}

int main()
{
    int z;
    cin>>z;
    for(int i=0;i<z;i++)
    {
        flaga=0;
        int czyToMaSens=0;
        if(naszyjnik[0][0]!=naszyjnik[1][0])
        {
            ok[1][0]=true;
            skad[1][0]=0;
            czyToMaSens=1;
        }
        if(naszyjnik[0][0]!=naszyjnik[1][1])
        {
            ok[1][1]=true;
            skad[1][1]=0;
            czyToMaSens=1;
        }
        if(czyToMaSens==1)
        {
            for(int i=1; i<n; i++)
                ukladajKorale(i);
            if(ok[n][0]==true)
            {
                if(naszyjnik[0][0])
                wypisz(0);
            }
            clean();
        }
        if(flaga!=1)
        {
            if(naszyjnik[0][1]!=naszyjnik[1][0])
            {
                ok[1][0]=true;
                skad[1][0]=1;
            }
            if(naszyjnik[0][1]!=naszyjnik[1][1])
            {
                ok[1][1]=true;
                skad[1][1]=1;
            }
            for(int i=1; i<n; i++)
                ukladajKorale(i);
            if(ok[n][1]==true)
                wypisz(1);
        }
        if(flaga==0)
            cout<< "-" << endl;
        clean();
    }
     return 0;
}

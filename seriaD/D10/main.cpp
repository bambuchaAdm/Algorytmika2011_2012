/**
*   Author: Adam Piekarczyk
*   Project Title: D10 - Naszyjnik
*   School Year: 2011/2012
*   School: VLO Kraków
*   Class: 1e
*

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int n, flaga;
vector<char> naszyjnik;
vector<bool> ok;
vector<int> skad;
char naszyjnik[1000005][2];
bool ok[1000005][2];
int skad [1000005][2];

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
*/
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
int isPossible = 0;

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
    for(int i=0; i<lkoral; i++)
    {
        //scanf("%c %c",&naszyjnik[i][0],&naszyjnik[i][1]);     //czemu to nie dziala? Zapytac kogos.
        cin >> naszyjnik[i][0] >> naszyjnik[i][1];
    }
    naszyjnik[lkoral][0] = naszyjnik[0][0];
    naszyjnik[lkoral][1] = naszyjnik[0][1];
}

void printOutput(int strona)
{
    if(isPossible==1)
        return;
    isPossible = 1;
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
    naszyjnik.clear();
    ok.clear();
    skad.clear();
}

void test()
{
    for(int i=0; i<=lkoral; i++)
        cout << ok[i][0];
    cout << endl;
    for(int i=0; i<=lkoral; i++)
        cout << ok[i][1];
    cout << endl;
}

void test1()
{
    for(int i=0; i<=lkoral; i++)
        cout << naszyjnik[i][0] << " " << naszyjnik[i][1] << endl;
}

void ukladajKorale()
{
    for(int i=1; i<lkoral; i++)
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
    for(int i=0; i<z; i++)
    {
        readInput();
        isPossible=0;
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
            if(ok[lkoral][0] && naszyjnik[0][0])
                printOutput(0);

            //isPossible = true;
            ok.clear();
            skad.clear();
            const int MAX = lkoral +1;
            skad.resize(MAX,vector<int>(2));
            ok.resize(MAX,vector<bool>(2,false));
        }
        if(isPossible!=1)
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
            if(ok[lkoral][1])
                printOutput(1);
        }
        if(isPossible==0)
            cout << "-" << endl;
	clean();

    }
    return 0;
}

/*
using namespace std;

int n, fail;
char naszyjnik[1000005][2];
bool tab[1000005][2];
int poprzednik [1000005][2];

void xx (int i)
{
       if(tab[i][0]==true)
       {

            if(naszyjnik[i][0]!=naszyjnik[i+1][0])
            {
                tab[i+1][0]=true;
                poprzednik[i+1][0]=0;
            }
            if(naszyjnik[i][0]!=naszyjnik[i+1][1])
            {
                tab[i+1][1]=true;
                poprzednik[i+1][1]=0;
            }
       }
       if(tab[i][1]==true)
       {
            if(naszyjnik[i][1]!=naszyjnik[i+1][0])
            {
                tab[i+1][0]=true;
                poprzednik[i+1][0]=1;
            }
            if(naszyjnik[i][1]!=naszyjnik[i+1][1])
            {
                tab[i+1][1]=true;
                poprzednik[i+1][1]=1;
            }
       }
}

void wypisz(int x)
{
    if(fail==1)
        return;
    fail=1;
    stack<char> s;
    x=poprzednik[n][x];
    s.push(naszyjnik[n-1][x]);
    for(int i=n-1; i>0; i--)
    {
        x=poprzednik[i][x];
        s.push(naszyjnik[i-1][x]);
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

void wyczysc()
{
    for(int i=0; i<=n; i++)
    {
        tab[i][0]=false;
        tab[i][1]=false;
    }
}
int main()
{
    int z;
    cin>>z;
    while(z--)
    {
    wyczysc();
    fail=0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>naszyjnik[i][0] >> naszyjnik[i][1];
    naszyjnik[n][0]=naszyjnik[0][0];
    naszyjnik[n][1]=naszyjnik[0][1];
    int gg=0;
    if(naszyjnik[0][0]!=naszyjnik[1][0])
    {
        tab[1][0]=true;
        poprzednik[1][0]=0;
        gg=1;
    }
    if(naszyjnik[0][0]!=naszyjnik[1][1])
    {
        tab[1][1]=true;
        poprzednik[1][1]=0;
        gg=1;
    }
    if(gg==1)
    {
        for(int i=1; i<n; i++)
            xx(i);
        if(tab[n][0]==true)
        {
            if(naszyjnik[0][0])
            wypisz(0);
        }
        wyczysc();
    }
   if(fail!=1)
   {
        if(naszyjnik[0][1]!=naszyjnik[1][0])
        {
            tab[1][0]=true;
            poprzednik[1][0]=1;
        }
        if(naszyjnik[0][1]!=naszyjnik[1][1])
        {
            tab[1][1]=true;
            poprzednik[1][1]=1;
        }
        for(int i=1; i<n; i++)
            xx(i);
        if(tab[n][1]==true)
            wypisz(1);
        }
        if(fail==0)
            cout<<"-"<<endl;
    }
     return 0;
}
*/

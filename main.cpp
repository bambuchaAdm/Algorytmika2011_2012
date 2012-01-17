#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 201;

int lwierzch;
pair<int,int> wierch[MAX];

void wczytaj()
{
    cin >> lwierzch;
    for(int i=0;i<lwierzch;i++)
        cin >> wierch[i].first >> wierch[i].second;
}

int do2(int a)
{
    return a*a;
}

int odleglosc(pair<int,int> w, pair<int,int> w1)
{
    return do2(w1.first-w.first) + do2(w1.second - w.second);
}

void trianguluj()
{
    int wynik[MAX][MAX];
    for(int i=0;i<lwierzch;i++)
        wynik[i][i]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][(i+1)%lwierzch]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][(i+2)%lwierzch]=0;
    for(int i=0;i<lwierzch;i++)
    {
        for(int j=3;i<lwierzch;i++)     //ew <=
        {
            for(int k=i;k<i+j;k++)
            {

            }
        }
    }
}

int main()
{
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        wczytaj();
        trianguluj();
    }
    return 0;
}

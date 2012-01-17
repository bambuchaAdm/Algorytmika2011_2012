#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 201;
const int k8 = 200000001;

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
        for(int j=3;j<lwierzch;j++)     //ew <=
        {
            wynik[i][(i+j)%lwierzch]=k8;
            for(int k=i;k<i+j;k++)
            {
                int wposr = wynik[i][(i+k)%lwierzch] +
                    wynik[(i+k+1)%lwierzch][(i+j)%lwierzch] +
                    odleglosc(wierch[i], wierch[(i+k)%lwierzch]) +
                    odleglosc(wierch[(i+k+1)%lwierzch]), wierch[(i+j)%lwierzch]);
                if(wposr < wynik[i][j+i])
                    wynik[i][j+i] = wposr;
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

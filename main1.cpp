#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 201;
const long long k8 = 200000001;

int lwierzch;
pair<long long,long long> wierch[MAX];
long long trasa[MAX][MAX];

void wczytaj()
{
    cin >> lwierzch;
    for(long long i=0;i<lwierzch;i++)
        cin >> wierch[i].first >> wierch[i].second;
}

long long do2(long long a)
{
    return a*a;
}

long long odleglosc(pair<long long,long long> w, pair<long long,long long> w1)
{
    return do2(w1.first-w.first) + do2(w1.second - w.second);
}

bool ifnotbok(int a, int b)
{
    if((a-b) != 1 && (a-b) != (-1) && (a-b) != 0)
        return true;
    else
        return false;
}

void rekonstruuj(long long i,long long j)
{
    if(j<i)
    {
        if((lwierzch-i+j)<=2)
            return;
    }
    else
    {
        if((j-i)<=2)
            return;
    }
    long long k=trasa[i][j];
    if(ifnotbok(k,i))
        cout << i << " " << k << " ";
    if(ifnotbok(j,k))
        cout << j << " " << k << " ";
    rekonstruuj(i,k);
    rekonstruuj(k,j);
}

void trianguluj()
{

    long long wynik[MAX][MAX]={{0}};
    for(int i=0;i<lwierzch;i++)
        for(int j=0;j<lwierzch;j++)
            trasa[i][j]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][i]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][(i+1)%lwierzch]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][(i+2)%lwierzch]=0;
    for(int i=0;i<lwierzch;i++)
    {
        for(int j=3;j<lwierzch;j++)
        {
            wynik[i][(i+j)%lwierzch]=k8;
            for(int k=i+1;k<i+j-1;k++)  //1 błąd
            {
                long long wposr = wynik[i][(i+k)%lwierzch] +
                    wynik[(i+k)%lwierzch][(i+j)%lwierzch] + //2 błąd
                    odleglosc(wierch[i], wierch[(i+k)%lwierzch]) +
                    odleglosc(wierch[(i+k+1)%lwierzch], wierch[(i+j)%lwierzch]);
                if(wposr < wynik[i][(j+i)%lwierzch])
                {
                    wynik[i][(j+i)%lwierzch] = wposr;
                    trasa[i][(i+j)%lwierzch] = k;
                }
            }
        }
    }
    cout << endl << wynik[0][lwierzch-1] << " ";
    /*cout << endl;
    for(int i=0;i<lwierzch;i++)
    {
        for(int j=0;j<lwierzch;j++)
            cout << wynik[i][j] << " ";
        cout << endl;
    }*/
    rekonstruuj(0,lwierzch-1);
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

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 201;
const int k8 = 200000001;

int lwierzch;
pair<int,int> wierch[MAX];
int trasa[MAX][MAX];

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

void rekonstruuj(int a, int b)
{
    if(a>b)
    if((lwierzch-a+b)<=2)
        return;
    else if((b-a)<=2)
        return;
    int podzial = trasa[a][b];
    cout << podzial << " ";
    rekonstruuj(a,podzial);
    rekonstruuj(podzial+1,b);
}

void odtworz(int i,int j)
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
    int k=trasa[i][j];
    if((k-i)!=1&&(k-i)!=-1&&(k-i)!=-0)
        cout<<i<<" "<<k<<" ";
    if((j-k)!=1&&(j-k)!=-1&&(j-k)!=-0)
        cout<<j<<" "<<k<<" ";
    odtworz(i,k);
    odtworz(k+1,j);
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
        for(int j=3;j<lwierzch;j++)
        {
            wynik[i][(i+j)%lwierzch]=k8;
            for(int k=i;k<i+j;k++)
            {
                int wposr = wynik[i][(i+k)%lwierzch] +
                    wynik[(i+k+1)%lwierzch][(i+j)%lwierzch] +
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
    cout << endl;
    for(int i=0;i<lwierzch;i++)
    {
        for(int j=0;j<lwierzch;j++)
            cout << wynik[i][j] << " ";
        cout << endl;
    }
    //rekonstruuj(0,lwierzch-1);
    odtworz(0,lwierzch-1);
    /*for(int i=0;i<lwierzch;i++)
    {
        for(int j=0;j<lwierzch;j++)
            cout << trasa[i][j];
        cout << endl;
    }*/
    cout << endl;
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

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXI = 11;

struct zloto
{
    int numer;
    int wartosc;
    int waga;
};

int kradnij()
{
    zloto tab[MAXI];
    int lprzed=0, plecak=0;
    scanf("%d %d",&lprzed,&plecak);
    tab[0].waga=0;
    tab[0].numer=0;
    tab[0].wartosc=0;
    for(int i=1;i<=lprzed;i++)
    {
        scanf("%d %d",&tab[i].waga,&tab[i].wartosc);
        tab[i].numer=i;
    }
    int pomoc[MAXI][MAXI]={0};
    /*for(int i=0;i<=lprzed;i++)
        pomoc[i][0]=0;
    for(int i=0;i<=lprzed;i++)
        pomoc[0][i]=0;*/
    for(int i=1;i<=lprzed;i++)
    {
        for(int j=1;j<=plecak;j++)
        {
            if(j<tab[i].waga)
                continue;
            int biore = tab[i].wartosc + pomoc[i-1][j-tab[i].waga];
            int niebiore = pomoc[i-1][j];
            pomoc[i][j]=max(biore,niebiore);
        }
    }

    for(int i=0;i<MAXI;i++)
        {for(int j=0;j<MAXI;j++)
            cout << pomoc[i][j] << " ";
        cout << endl;}
        cout << endl;
    return pomoc[lprzed][plecak];
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        printf("%d\n",kradnij());
    return 0;
}

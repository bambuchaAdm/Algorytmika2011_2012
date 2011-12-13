#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100;

struct zloto
{
    int numer;
    int wartosc;
    int waga;
};

int kradnij()
{
    zloto tab[MAX];
    int lprzed=0, plecak=0;
    scanf("%d %d",&lprzed,&plecak);
    tab[0].waga=0;
    tab[0].numer=0;
    tab[0].wartosc=0;
    for(int i=1;i<lprzed;i++)
    {
        scanf("%d %d",&tab[i].waga,&tab[i].wartosc);
        tab[i].numer=i;
    }
    int pomoc[MAX][MAX];
    for(int i=0;i<=lprzed;i++)
        pomoc[i][0]=0;
    for(int i=0;i<=lprzed;i++)
        pomoc[0][i]=0;
    for(int i=1;i<=lprzed;i++)
    {
        for(int j=1;j<=plecak;j++)
        {
            int wagtemp=plecak;
            int biore=0, niebiore=0;
            biore=tab[i].wartosc + pomoc[i-1][wagtemt-tab[i].waga];
        }
    }
    return -1;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        printf("%d\n",kradnij());
    return 0;
}

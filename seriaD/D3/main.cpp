<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const long long MAX = 1000001;

int remontuj()
{
	int ldziur=0;
	scanf("%d",&ldziur);
	int koszt[MAX]={0};
	int wspolrzedna[MAX]={0};
	for(int i=1;i<=ldziur;i++)
	{
		scanf("%d %d",&wspolrzedna[i],&koszt[i]);
    }
	int dllaty=0, cenalaty=0;
	scanf("%d %d",&dllaty,&cenalaty);
	int pomoc[MAX] = {0};
    int ost=0;
	for(int i=0;i<=ldziur;i++)
	{
		int latamy, nielatamy;
		nielatamy = koszt[i] + pomoc[i-1];
        while(wspolrzedna[ost]<wspolrzedna[i]-dllaty)
            ost++;
		latamy = cenalaty + pomoc[ost-1];
		pomoc[i] = min(latamy,nielatamy);
	}

	return pomoc[ldziur];
}

int main()
{
	int z=0;
	scanf("%d",&z);
	for(int i=0;i<z;i++)
		printf("%d\n",remontuj());
	return 0;
}
=======
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXI = 10001;

struct zloto
{
    int numer;
    int wartosc;
    int waga;
};

zloto tab[MAXI];

int kradnij()
{
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
    int pomoc[MAXI][MAXI]={{0}};
    for(int i=1;i<=lprzed;i++)
    {
        for(int j=1;j<=plecak;j++)
        {
            if(j<tab[i].waga)
            {
                pomoc[i][j]=pomoc[i-1][j];
                continue;
            }
            int biore = tab[i].wartosc + pomoc[i-1][j-tab[i].waga];
            int niebiore = pomoc[i-1][j];
            pomoc[i][j]=max(biore,niebiore);
        }
    }
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
>>>>>>> a7c53450f4b8f57640b5dfebc76be190f3bed046

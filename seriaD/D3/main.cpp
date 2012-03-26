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

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 10;

int remontuj()
{
	int ldziur=0;
	scanf("%d",&ldziur);
	int koszt[MAX+1]={0};
	int wspolrzedna[MAX+1]={0};
	for(int i=1;i<=ldziur;i++)
	{
		scanf("%d %d",&wspolrzedna[i],&koszt[i]);
    }
	int dllaty=0, cenalaty=0;
	scanf("%d %d",&dllaty,&cenalaty);
	int pomoc[MAX+1] = {0};

	for(int i=0;i<=ldziur;i++)
	{
		int latamy, nielatamy;
		nielatamy = koszt[i] + pomoc[i-1];
		int zas = lower_bound(&wspolrzedna[0],&wspolrzedna[MAX+1],wspolrzedna[i]-dllaty) - &wspolrzedna[0];
		latamy = cenalaty + pomoc[zas];
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

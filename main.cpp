#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100;

struct zloto
{
    int numer;
    int wartosc;
    int waga;
}

int kradnij()
{
    zloto tab[MAX];
    int lprzed=0, plecak=0;
    scanf("%d %d",&lprzed,&plecak);
    zloto[i].waga=0;
    zloto[i].numer=0;
    zloto[i].wartosc=0;
    for(int i=1;i<lprzed;i++)
    {
        scanf("%d %d",&zloto[i].waga,&zloto[i].wartosc);
        zloto[i].numer=i;
    }

}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        printf("%d\n",kradnij());
    return 0;
}

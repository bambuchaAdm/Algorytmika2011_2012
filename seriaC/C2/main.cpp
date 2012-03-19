#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> moduly;
int sumamod=0;
int lmodulow=0, llotow=0;
int masaNajciezszego=0;

void wczytaj()
{
    moduly.clear();
    sumamod=0;
    lmodulow=0;
    llotow=0; masaNajciezszego=0;
    scanf("%d %d",&lmodulow,&llotow);
    for(int i=0;i<lmodulow;i++)
    {
        int a=0;
        scanf("%d",&a);
        if(a>masaNajciezszego)
            masaNajciezszego=a;
        moduly.push_back(a);
        sumamod+=a;
    }
}

int wyznacz_ladownosc()
{
    int koniec=sumamod;
    while(masaNajciezszego!=sumamod)
    {
        int srodek=(masaNajciezszego+sumamod)/2;
        int suma=0, loty=0;
        for(int i=0;i<lmodulow;i++)
        {
            suma+=moduly[i];
            if(suma>srodek)
            {
                loty++;
                suma=moduly[i];
            }
            else
                if(suma==srodek)
                {
                    loty++;
                    suma=0;
                }
        }
        if(suma>0)
            loty++;
        if(loty>llotow)
            masaNajciezszego=srodek+1;
        else
            sumamod=srodek;
        if(loty<=llotow&&srodek<koniec)
            koniec=srodek;

    }
    return koniec;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        wczytaj();
        printf("%d\n",wyznacz_ladownosc());
    }
    return 0;
}

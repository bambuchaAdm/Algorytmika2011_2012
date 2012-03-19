#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<int> zeznania;
vector<int> zapytania;
int lzapytan=0;

void quicksort(int b, int e)
{
    int b1 = b, e1=e;
    int podzial = (b+e)/2;
    while(b<e)
    {
        while(zeznania[b]<=zeznania[podzial])
            b++;
        while(zeznania[e]>zeznania[podzial])
            e--;
        //if(zeznania[b]>zeznania[e])
            {swap(zeznania[b],zeznania[e]); b++; e--;}
    }
    if(b1<e)    quicksort(b1, e);
    if(e1>b)    quicksort(b,e1);
}

void swap(int a, int b)
{
    a^=b;
    b^=a;
    a^=b;
}

void wczytaj()
{
    zeznania.clear();
    zapytania.clear();
    int lzeznan=0;
    scanf("%d",&lzeznan);
    for(int i=0;i<lzeznan;i++)
    {
        int a=0;
        scanf("%d",&a);
        zeznania.push_back(a);
    }
    quicksort(0,zeznania.size()-1);
    for(int i=0;i<zeznania.size();i++)
        cout << zeznania[i] << " ";
    cout << endl;
    lzapytan=0;
    scanf("%d",&lzapytan);
    for(int i=0;i<lzapytan;i++)
    {
        int a=0;
        scanf("%d",&a);
        zapytania.push_back(a);
    }

}

int dolny_zakres(int a)
{
    int poczatek=0;
    int koniec=zeznania.size()-1;
    while(poczatek<=koniec)
    {
        int srodek=(poczatek+koniec)/2;
        if(poczatek==koniec)
            if(zeznania[poczatek]==a)
                return poczatek;
            else
                return -1;
        if(zeznania[srodek]==a)
        {
            koniec=srodek;
            continue;
        }
        if(zeznania[srodek]<a)
        {
            poczatek=srodek+1;
            continue;
        }
        if(zeznania[srodek]>a)
        {
            koniec=srodek;
            continue;
        }
    }
    return -1;
}

int gorny_zakres(int a)
{
    int poczatek=0;
    int koniec=zeznania.size()-1;
    while(poczatek<=koniec)
    {
        int srodek=(poczatek+koniec+1)/2;
        if(poczatek==koniec)
            if(zeznania[poczatek]==a)
                return poczatek+1;
            else
                return -1;
        if(zeznania[srodek]>a)
        {
            koniec=srodek-1;
            continue;
        }
        if(zeznania[srodek]==a)
        {
            poczatek=srodek;
            continue;
        }
        if(zeznania[srodek]<a)
        {
            poczatek=srodek+1;
            continue;
        }
        }
    return -1;
}

int wyznacz_ilosc(int a, int b)
{
    if(a==-1)
        return 0;
    return b-a;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        wczytaj();
        for(int j=0;j<lzapytan;j++)
        {
         printf("%d\n",wyznacz_ilosc(dolny_zakres(zapytania[j]),gorny_zakres(zapytania[j])));
        }
    }
    return 0;
}

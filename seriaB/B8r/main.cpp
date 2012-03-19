#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

long long silnia(int liczba)
{
    if(liczba==0) return 1;
    long long wynik=1;
    for(int i=1;i<=liczba;i++)
        wynik*=i;
    return wynik;
}

long long wylicz_indeks(int liczba, vector<int> permutacja)
{
    long long wynik=0;
    long long wynikost=0;
    set<int> porzadek;
    int numer=1;
    for(int i=liczba-1;i>=0;i--)
    {
        int miejsce=0;
        for(set<int>::iterator it=porzadek.begin();it!=porzadek.lower_bound(permutacja[i]);it++)
            miejsce++;
        wynik=miejsce*silnia(numer-1);
        wynikost+=wynik;
        porzadek.insert(permutacja[i]);
        numer++;
       // cout << wynik << "  ";
    }
    return wynikost+1;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    printf("%d\n",z);
    for(int i=0;i<z;i++)
    {
        int liczba=0;
        vector<int> permutacja;
        scanf("%d",&liczba);
        for(int j=0;j<liczba;j++)
        {
            int a=0;
            scanf("%d",&a);
            permutacja.push_back(a);
        }
        printf("%d %lld\n",liczba,wylicz_indeks(liczba, permutacja));
    }
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

long long silnia(int liczba)
{
    if(liczba==0)
        return 1;
    long long sil=1;
    for(int i=1;i<=liczba;i++)
        sil*=i;
    return sil;
}

void permutuj()
{
    int n=0, indeksper=0;
    scanf("%d %d",&n,&indeksper);
    printf("%d ",n);
    indeksper--;
    int war=true;
    int war1=n;
    int licznik=1;
    while(n>0)
    {
        cout << indeksper/silnia(n-1)+licznik << " ";
        indeksper=indeksper%silnia(n-1);
        n--;

        if(war)
        {licznik++; if(licznik==war1) {war=false; licznik--;}}
        else
        licznik--;

    }
    cout << endl;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    printf("%d\n",z);
    for(int i=0;i<z;i++)
        permutuj();
    return 0;
}

#include <cstdio>
#include <set>
using namespace std;

void dookola()
{
    set<int> atrakcje;
    int dlwycieczki=0;
    scanf("%d",&dlwycieczki);
    for(int i=0;i<dlwycieczki;i++)
    {
        int a=0;
        scanf("%d",&a);
        atrakcje.insert(a);
    }
    int zapytania=0;
    scanf("%d",&zapytania);
    for(int i=0;i<zapytania;i++)
    {
        int pytanie=0;
        scanf("%d",&pytanie);
        set<int>::iterator itup,itlow;
        itup=atrakcje.upper_bound(pytanie);  //generujemy iteratory dla gory i dolu
        itlow=atrakcje.lower_bound(pytanie);
        if(*itlow==pytanie)         //jezeli wartos wskazywana przez dolny jest rowna zapytaniu to musi byc to najblizsza atrakcja, czyli znalezlismy odpowiedz
        {
            printf("%d ",*itlow); continue;
        }
        if(itlow==atrakcje.end()&&itup==atrakcje.end())     //jezeli oba iteratory nie znalazly elementow spelniajacych ich warunki(czyli wskazuja na element za setem) to oznacza ze
                                                            //najblizszym elementem musi byc najwiekszy dzien w secie, czyli ostatni element setu
        {
            itup=atrakcje.end();
            itup--;
            printf("%d ", *itup); continue;

        }
        if(itlow!=atrakcje.begin())     //jezeli lowet_bound nie wskazal na pierwszy element to cofamy iterator o jeden element(zapobiegamy wykrzaczaniu przez wychodzenie cholera wie gdzie)
        itlow--;
        if(pytanie-(*itlow)<=(*itup)-pytanie)       //sprawdzamy odleglosc zapytania od dwoch najblizszych elementow i wywalamy mniejsza
            printf("%d ",*itlow);
        else
            printf("%d ",*itup);
    }
    printf("\n");       //cieszymy sie zwyciestwem
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        dookola();
    return 0;
}

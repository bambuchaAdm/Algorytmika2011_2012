#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct obywatel
{
    char imie[11];
    int numer;
};

vector<obywatel> tab;

void merge(int po, int sr, int kon)
{
    vector<obywatel> pomoc;
    pomoc=tab;
    int i, j, q;
    i = po; j= sr+1; q = po;
    while(i<=sr && j<=kon)
        if(pomoc[i].numer<pomoc[j].numer)
            {tab[q]=pomoc[i];q++;i++;}
        else
            {tab[q]=pomoc[j];q++;j++;}
    while(i<=sr)
        {tab[q]=pomoc[i]; q++; i++;}
}

void mergesort(int b, int e)
{
    if(b<e)
    {
        int podzial=(b+e)/2;
        mergesort(b,podzial);
        mergesort(podzial+1,e);
        merge(b,podzial,e);
    }

}

void paruj()
{
    tab.clear();
    int lucz=0;
    int liczba=0;
    cin >> lucz >> liczba;
    for(int i=0;i<lucz;i++)
    {
        tab.push_back(obywatel());
        scanf("%s",tab[i].imie);
        cin >> tab[i].numer;
    }
    mergesort(0,tab.size()-1);
    int b=0, e=tab.size()-1;
    while(b<e)
    {
        if(tab[b].numer+tab[e].numer==liczba)
            {cout << tab[b].imie << " " << tab[e].imie << endl; return;}
        if(tab[b].numer+tab[e].numer>liczba)
            e--;
        if(tab[b].numer+tab[e].numer<liczba)
            b++;
    }
    cout << "NIE" << endl;
}

int main()
{
    int zd;
    cin >> zd;
    for(int i=0;i<zd;i++)
    {
        paruj();
    }
    return 0;
}

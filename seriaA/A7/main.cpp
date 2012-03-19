#include <cstdio>
#include <iostream>

/*problem ogolnie jest taki, ze program uparcie analizuje tylko jeden zestaw danych, reszte olewa. Komentarzy lepszych nie chce mi sie pisac, pozno jest*/

using namespace std;

int znajdz_gwiazdke(char tab[]) //funkcja szuka pierwszej gwiazdki w tablicy
{
    for(int i=0;i<100000;i++)
    {
        if(tab[i]==char(42))
            return i;
    }
}

int dodawanie(char dod1[], char dod2[])    //funkcja dodaje liczby, z podzialem na 3 przypadki zaleznie od dlugosci obu liczb
{
    int licz1=znajdz_gwiazdke(dod1)-2;              //na moje oko to tu powinno byc minus 1, lecz jak jest to daje idiotyczne wyniki. Tak wiec stalo sie 2.
    int licz2=znajdz_gwiazdke(dod2)-2;
    int wynik=0, przerzut =0;

    if(licz1>licz2)
    {
        for(int i=licz2;i>=0;i--)       //sumujemy liczby
        {
            wynik=dod1[licz1]-'0'+dod2[i]-'0'+przerzut;
            dod1[licz1]=char(wynik%10+'0');
            przerzut=wynik/10;
            licz1--;
        }
        while(przerzut!=0)      //tutaj dbamy o to zeby przeniesienie zostalo uwzglednione.
        {
            wynik=dod1[licz1]-'0'+przerzut;
            dod1[licz1]=char(wynik%10+'0');
            przerzut=wynik/10;
            licz1--;
            if(licz1<0)
            {
                if(dod1[0]=='0')
                    cout <<'1';
                int a =0;
                while(dod1[a]!=char(42))
                {
                    cout << dod1[a];
                    a++;
                }
                cout<<endl;
                return 0;
            }
        }
        int a =0;
        while(dod1[a]!=char(42))        //wypisujemy wynik jezeli nie ma przeniesienia
        {
            cout << dod1[a];
            a++;
        }
        cout<<endl;
        return 0;
    }
    if(licz1<licz2)
    {
        for(int i=licz1;i>=0;i--)
        {
            wynik=dod2[licz2]-'0'+dod1[i]-'0'+przerzut;
            dod2[licz2]=char(wynik%10+'0');
            przerzut=wynik/10;
            licz2--;
        }
        while(przerzut!=0)
        {
            wynik=dod2[licz2]-'0'+przerzut;
            dod2[licz2]=char(wynik%10+'0');
            przerzut=wynik/10;
            licz2--;
            if(licz2<0)
            {
                if(dod2[0]=='0')
                    cout <<'1';
                int a =0;
                while(dod2[a]!=char(42))
                {
                    cout << dod2[a];
                    a++;
                }
                cout<<endl;
                return 0;
            }
        }
        int a =0;
        while(dod2[a]!=char(42))
        {
            cout << dod2[a];
            a++;
        }
        cout<<endl;
        return 0;
    }
    if(licz1==licz2)
    {
        /*for(int i=licz2;i>=0;i--)
        {
            wynik=dod2[i]-'0'+dod1[i]-'0'+przerzut;
            dod2[i]=char(wynik%10+'0');
            przerzut=wynik/10;
        }*/
        for(int i=licz1;i>=0;i--)
        {
            wynik=dod2[i]-'0'+dod1[i]-'0'+przerzut;
            dod2[i]=char(wynik%10+'0');
            przerzut=wynik/10;
            licz2--;
        }
        while(przerzut!=0)
        {
            wynik=dod2[licz2]-'0'+przerzut;
            dod2[licz2]=char(wynik%10+'0');
            przerzut=wynik/10;
            licz2--;
            if(licz2<0)
            {
                if(przerzut!=0)
                    cout <<'1';
                int a =0;
                while(dod2[a]!=char(42))
                {
                    cout << dod2[a];
                    a++;
                }
                cout<<endl;
                return 0;
            }
        }

        /*if(przerzut!=0)
            {
                cout <<'1';
                int a=0;
                while(dod2[a]!=char(42))
                {
                    cout << dod2[a];
                    a++;
                }
                cout << endl;
                return;
            }*/
        int a =0;
        while(dod2[a]!=char(42))
                {
                    cout << dod2[a];
                    a++;
                }
        cout << endl;
        return 0;

    }
}

int main()
{
    int Z=0;
    scanf("%d",&Z);
    //for(int i=0;i<Z;i++)
    while(Z>0)
    {
        char sklad1[100000], sklad2[100000];
        for(int j=0; j<100000;j++)
        {
            sklad1[j]=char(42);
            sklad2[j]=char(42);
        }
        scanf("%s",sklad1);
        scanf("%s",sklad2);
        dodawanie(sklad1, sklad2);
        Z--;
    }
    return 0;
}

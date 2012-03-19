#include <iostream>
#include <cstdlib>
#include <cstdio> //poproboje tej biblioteki, moze fajniejsza jest.

/* wydaje sie ze uzycie 3 osi to byl durny pomysl*/
/*Ten kod to swietny przyklad jak NIE nalezy zabierac sie do zadania! Nie komplikujmy rzeczy prostych! Dla pewnych przypadkow skladanie 3 osi w 2 wymusza pozniejsze ich rozlozenie, ergo to nie ma sensu*/

using namespace std;

int z = 0; int x = 0; int y = 0; int skret=2; int ostskret=0; //takie tam zmienne globalne, nie jestem pewien czy one koniecznie tu musza byc, ale tak chyba bezpieczniej

void f1(int a);
void tworzenie_sygnalu(int a, int b, int c);

int main()
{
    int lzest = 0;
    cin >> lzest;
    for(int i=0;i<lzest;i++)
    {
        int linst=0;
        cin >> linst;
        if(!linst)
            {cout << 0 << endl; continue;} //to na wypadek zerowej liczby instrukcji
        z=0;x=0;y=0;skret=0;        //pobieramy ilosc zestawow i zerujemy wspolrzedne
        f1(linst);                  //odpalamy funkcje, ktora ogarnia przetwarzanie instrukcji na wspolrzedne
        tworzenie_sygnalu(z,x,y);
    }
    return 0;
}

void skret_zlowia(char s_instr, int s_para)     //ta funkcja ma za zadanie wyzanczyc kierunek w ktorym lezie zlow na podstawie dodawania i odejmowania wartosci kata zaleznie od kierunku obrotu i dzielac to przez modulo 360. os x to 2-5, y to 3-4, z to 1-6.
{
    if(s_instr=='R')
    {
        ostskret+=s_para;
    }
    else
    {
        ostskret-=s_para;
    }
    if(ostskret%360==0) skret = 2;
    if(ostskret%360==60 || ostskret%360==-300) skret = 3;
    if(ostskret%360==120 || ostskret%360==-240) skret = 6;
    if(ostskret%360==180 || ostskret%360==-180) skret = 5;
    if(ostskret%360==240 || ostskret%360==-120) skret = 4;
    if(ostskret%360==300 || ostskret%360==-60) skret = 1;
}

void zmien (int z_skret, int z_para, int z_zwrot)       //ta funkcja zmienia wartosci wspolrzednych na podstawie skretu o podany parametr - ruch. Zwrot sluzy do zorientowania sie czy trzeba dodawac czy odejmowac, czyli czy zlow cofa sie czy idze do przodu.
{
    if(z_skret==2)
        {if(z_zwrot==1) {x+=z_para;}
        else {x-=z_para;}}
    if(z_skret==5)
        {if(z_zwrot==1) {x-=z_para;}
        else {x+=z_para;}}
    if(z_skret==3)
        {if(z_zwrot==1) {y+=z_para;}
        else {y-=z_para;}}
    if(z_skret==4)
        {if(z_zwrot==1) {y-=z_para;}
        else {y+=z_para;}}
    if(z_skret==1)
        {if(z_zwrot==1) {z+=z_para;}
        else {z-=z_para;}}
    if(z_skret==6)
        {if(z_zwrot==1) {z-=z_para;}
        else {z+=z_para;}}
}

void f1 (int a)                 //ogarniamy pobieranie kolejnych instrukcji i ich odpowiednie przetwarzanie
{
    char instr = 0; int para = 0; int zwrot = 1;  ostskret=0; skret=2;
    for(int i=0;i<a;i++)
    {
        cin >> instr >> para;
        if(instr=='F')
            zwrot=1;
        else
            zwrot=2;
        if(instr=='F'||instr=='B')
            zmien(skret,para,zwrot);
        if(instr=='R'||instr=='L')
            skret_zlowia(instr,para);
    }
}

void tworzenie_sygnalu(int a, int b, int c)         //funkcja ma poskladac osie do kupy i zakodowac instrukcje
{
    if(a>0 && c>0)      //syntezujemy osie z i y, tak ze zostaje nam odpowiednio zmieniony x, jedna z z/y wyzerowana, a druga wskazuje dalej na ruch w swoim kierunku
    {
        if(a>c)
        {
            b+=c;
            a-=c;
            c=0;
        }
        else
        {
            b+=a;
            c-=a;
            a=0;
        }
    }
    if(a<0 && c<0)
    {
        if(a>c)
        {
            b+=a;
            c-=a;
            a=0;
        }
        else
        {
            b+=c;
            a-=c;
            c=0;
        }
    }

    if(b>0 && a<0)
    {
        if(b>=abs(a))
        {
            b-=abs(a);
            c+=abs(a);
            a=0;
        }
        else
        {
            c+=b;
            a+=b;
            b=0;
        }
    }
  //dobre do tutaj
    if(c>0 && b<0)
    {
        if(c>=abs(b))
        {
            c-=abs(b);
            a+=b;
            a=0;
        }
        else
        {
            b+=c;
            a-=c;
            c=0;
        }
    }
//chyba good
    if(b<0 && a>0)
    {
        if(a>=abs(b))
        {
            a-=abs(b);
            c+=a;
            b=0;
        }
        else
        {
            b+=a;
            c-=a;
            a=0;
        }
    }
//hope everything is alright
    if(b>0 && c<0)
    {
        if(b>=abs(c))
        {
            b-=abs(c);
            a+=abs(c);
            c=0;
        }
        else
        {
            c+=b;
            a+=b;
            b=0;
        }
    }

    cout << a << b << c << ostskret << endl; //linijka testowa
    /*JEDZIEMY Z TWORZENIEM KOMUNIKATU KOŃCOWEGO*/

   // if(b>=0 && c>=0 && (c!=0 || b!=0))    //robimy wszystkie mozliwosci ruchu dla prawej gornej czesci miedzy osiami x i y
   // {
       /* if(!b)
        {
            cout << 2 << endl;
            if(ostskret==60||-300)
                cout << "R 60 F " << c;
            else cout << "L 120 B " << c;
            return;
        }*/ //mam nadzieje pozbyc sie tej funkcji bo to juz jest nadmiar kodu.

     /*   if(ostskret==60 || ostskret==-300)
            {
                if(b||c)
                    cout << "3" << endl;
                else
                    cout << "2" << endl;
                if(b)
                    cout << "F " << b << " ";
                cout << "R 60 ";
                if(c)
                    cout << "F " << c << " " << endl;
                return;
            }
        if(ostskret==240 || ostskret==-120)
            {
                if(b||c)
                    printf("3\n");
                else
                    printf("2\n");
                if(b)
                    printf("F %d ",b);
                printf("L 120");        //to jest dowod na to ze cstdio jest czytelniejsze!
                if(c)
                    printf("B %d \n",c);
                return;
            }
        if(ostskret==300 || ostskret==-60)
            {
                if(b||c)
                    printf("3\n");
                else
                    printf("2\n");
                if(b&&c)
                    printf("F %d ",b+c);
                if(c&&!b)
                    printf("F %d ",c);          //TODO poprawić to i sprawdzić czy na stówę działa dobrze! TODO p rzerobić resztę warunków!
                if(!c)
                    printf("F %d",b);
                printf("L 60");
                return;
            }
        if(ostskret==120 || ostskret==-240)
            {
                if(b)
                    printf("3\n");
                else
                    printf("2\n");
                if(b)
                    printf("F %d ",b+c);
                else
                    printf("F %d ",c);
                printf("R 120 F %d \n",c);
                return;
            }
        if(ostskret==0)
            {
                if(b)
                    printf("3\n");
                else
                    printf("2\n");
                if(b)
                    printf("F %d ",b);
                printf("L 120 B %d \n",c);
                return;
            }
        if(ostskret==240 || ostskret==-120)
            {
                if(b)
                    printf("3\n");
                else
                    printf("2\n");
                if(b)
                    printf("F %d ",b);
                printf("L 120 B %d \n",c);
                return;
            }

    } */

    /*if(b&&c&&!a)
    {
        if(ostskret==60||-300)
        {
            printf("3\n")
            if(b>0)
            {
                printf("F %d R 60 ",b)
                if(c>0)
                    printf("F %d\n",c)
                else
                    printf("B %d\n",-c)
            }
            else
            {
                printf("B %d R 60 ",-b)
                if(c>0)
                    printf("F %d\n",c)
                else
                    printf("B %d\n",-c)
            }
        }
        if(ostskret==-60||300)
        {
            printf("3\n")
            if(b>0)
            {
                printf("F %d L 120 ",b)
                if(c>0)
                    printf("F %d\n",c)
                else
                    printf("B %d\n",-c)
            }
            else
            {
                printf("B %d L 120 ",-b)
                if(c>0)
                    printf("F %d\n",c)
                else
                    printf("B %d\n",-c)
            }
        }
    }*/



}

#include <cstdio>
#include <iostream>

using namespace std;

/*zmienne globalne*/

int skret = 0; //przechowuje wartosc skretu
int x=0;
int y=0; //przechowuje wartosci punktu - osi x i y

void zmienxy(int para1, char instr)          //funkcja zmienia wartosci polozenia na obu osiach, czyli wspolrzedne.
{
    if(skret==0)
       {if(instr=='F') {y+=para1;}
       else {y-=para1;}}
    if(skret==60 || skret==-300)
       {if(instr=='F') {x+=para1;}
       else {x-=para1;}}
    if(skret==-120 || skret==240)
       {if(instr=='F') {x-=para1;}
       else {x+=para1;}}
    if(skret==180 || skret==-180)
       {if(instr=='F') {y-=para1;}
       else {y+=para1;}}
    if(skret==120 || skret==-240)
        {if(instr=='F'){y-=para1; x+=para1;}
        else {y+=para1; x-=para1;}}
    if(skret==-60 || skret==300)
        {if(instr=='F') {y+=para1; x-=para1;}
        else {y-=para1; x+=para1;}}
}

void zmienskret(char instr, int para1)       //funkcja wyznacza skret zlowia po kazdym obrocie.
{
    if(instr=='R')
        skret=(skret+para1)%360;
    else
        skret=(skret-para1)%360;
}

void wyznacz_punkt(int linstr)      //funkcja  zajmuje sie znalezieniem punktu w ktorym zlow sie zatrzyma w ukladzie wspolrzednych i kacie miedzy x i y rownym 60 stopni
{
    char instr = char(0);
    int para1 = 0;
    for(int i=0; i<linstr;i++)
    {
        //scanf("%s",&instr);       //scanfy powodowaly segmentation fault, nad ktorym siedzialem pare godzin szukajac dziury w calym. po zastapieniu przez cin dziala.
        //scanf("%d",&para1);
        cin >> instr;
        cin >> para1;
        if(instr=='F'||instr=='B')
            zmienxy(para1, instr);
        else
            zmienskret(instr,para1);
    }
}

void znormalizuj_skret()        //funkcja likwiduje ujemne wartosci skretu, zeby mozna bylo sie obracac tylko i wylacznie w prawo. upraszcza kod.
{
    if(skret==-60)
        skret=300;
    if(skret==-120)
        skret=240;
    if(skret==-180)
        skret=180;
    if(skret==-240)
        skret=120;
    if(skret==-300)
        skret=60;
}

int stworz_komunikat()     //funkcja ma za zadanie stworzyc odpowiedz do zadania. po kolei analizujemy przypadki dla 1 komendy, 2, 3 i 4.
{
    if(x==0&&y==0&&skret==0)
        {printf("0\n\n"); return 0;}
    if(x==0&&y==0)
        {printf("1\nR %d \n",skret); return 0;}
    if(y!=0&&x==0&&skret==0)
        {if(y>0)
            {printf("1\nF %d\n",y); return 0;}
        else
            {printf("1\nB %d\n",(-y)); return 0;}}
    if(x==0&&y!=0&&skret!=0)
        {if(y>0)
            {printf("2\nF %d R %d\n",y,skret); return 0;}
        else
            {printf("2\nB %d R %d\n",(-y),skret); return 0;}}
    if(skret==60&&(y==0&&x!=0))
        {if(x>0)
            {printf("2\nR %d F %d\n",skret,x); return 0;}
        else
            {printf("2\nR %d B %d\n",skret,(-x)); return 0;}}
    if(skret==240&&(y==0&&x!=0))
        {if(x>0)
            {printf("2\nR %d B %d\n",skret,x); return 0;}
        else
            {printf("2\nR %d F %d\n",skret,(-x)); return 0;}}
    if(skret==120&&(x==(-y) || y==(-x)))
        {if(x>0)
            {printf("2\nR %d F %d \n",skret,x); return 0;}
        else
            {printf("2\nR %d B %d \n",skret,(-x)); return 0;}}
    if(skret==300&&(x==(-y) || y==(-x)))
        {if(x>0)
            {printf("2\nR %d B %d \n",skret,x); return 0;}
        else
            {printf("2\nR %d F %d \n",skret,(-x)); return 0;}}
    if(skret==180&&(x==0&&y<0))
        {printf("2\nR %d F %d",skret,(-y));return 0;}
            if(skret==60)
            {
                if(y>0)
                    printf("3\nF %d ",y);
                else
                    printf("3\nB %d ",(-y));
                printf("R %d ",skret);
                if(x>0)
                    {printf("F %d \n",x); return 0;}
                else
                    {printf("B %d \n",(-x)); return 0;}
            }
            if(skret==240)
            {
                if(y>0)
                    printf("3\nF %d ",y);
                else
                    printf("3\nB %d ",(-y));
                printf("R %d ",skret);
                if(x<0)
                    {printf("F %d \n",(-x)); return 0;}
                else
                    {printf("B %d \n",x); return 0;}
            }
            if(skret==120)
            {
                if(y>=0)
                    if(x>0) printf("3\nF %d ",y+x);
                    else
                    {
                        if(y+x<0) printf("3\nB %d ",(-(y+x)));
                        else printf("3\nF %d ",y+x);
                    }
                else
                    if(x>0)
                        {
                            if((-((-y)-x))>0) printf("3\nF %d ",(-((-y)-x)));
                            else printf("3\nB %d ",((-y)-x));
                        }
                    else printf("3\nB %d ",(-y)+(-x));
                printf("R %d ",skret);
                if(x<0)
                    {printf("B %d \n",(-x)); return 0;}
                else
                    {printf("F %d \n",x); return 0;}
            }
            if(skret==300)
            {
                if(y>=0)
                    if(x>0) printf("3\nF %d ",y+x);
                    else
                    {
                        if(y+x<0) printf("3\nB %d ",(-(y+x)));
                        else printf("3\nF %d ",y+x);
                    }
                else
                    if(x>0)
                    {
                        if(((-((-y)-x)))>0) printf("3\nF %d ",(-((-y)-x)));
                        else printf("3\nB %d ",((-y)-x));
                    }
                    else printf("3\nB %d ",(-y)+(-x));
                printf("R %d ",skret);
                if(x<0)
                    {printf("F %d \n",(-x)); return 0;}
                else
                    {printf("B %d \n",x); return 0;}
            }
            if(skret==0&&(y==(-x)||(-y)==x))
            {
                if(y>0) printf("3\nR 120 B %d R 240\n",y);
                else printf("3\nR 120 F %d R 240\n",(-y));
                return 0;
            }
            if(skret==180&&(y==(-x)||(-y)==x))
            {
                if(y>0) printf("3\nR 120 B %d R 60\n",y);
                else printf("3\nR 120 F %d R 60\n",(-y));
                return 0;
            }

        if(y>0)
            printf("4\nF %d ",y);
        else
            if(y!=0) printf("4\nB %d ",(-y));
            else printf("3\n");
        if(x>0)
            printf("R 60 F %d ",x);
        else
            printf("R 60 B %d ",(-x));
        if(skret==180)
            {printf("R 120\n"); return 0;}
        else
            {printf("R 300\n"); return 0;}
}

int main()
{
    int z1 = 0;
    scanf("%d",&z1);
    for(int i=0;i<z1;i++)
    {
        int l=2;
        x=0;y=0;skret=0;
        int linstr = 0;
        scanf("%d",&linstr);
        wyznacz_punkt(linstr);
        znormalizuj_skret();
        l=stworz_komunikat();       //podstawienie powstalo na drodze radzenia sobie z segmentation fault.
    }
    return 0;
}

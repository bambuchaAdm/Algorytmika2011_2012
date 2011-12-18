#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX = 3001;

struct pole
{
    int wartosc;
    short kierunek;
};

pole pomoc[MAX][MAX];

void liczpodciag()
{
    string obecny;
    string docelowy;
    cin >> obecny >> docelowy;
    int x = docelowy.size();
    int y = obecny.size();

    for(int i=0;i<=x;i++)
        pomoc[i][0].wartosc = 0;
    for(int i=0;i<=y;i++)
        pomoc[0][i].wartosc = 0;

    for(int j=1;j<=y;j++)
    {
        for(int i=1;i<=x;i++)
        {
            if(obecny[j-1]==docelowy[i-1])
            {
                pomoc[j][i].wartosc = 1 + pomoc[j-1][i-1].wartosc;
                pomoc[j][i].kierunek = 3;
            }
            else
            {
                int lewo=0,gora=0;
                gora = pomoc[j][i-1].wartosc;
                lewo = pomoc[j-1][i].wartosc;
                if(gora < lewo)
                {
                    pomoc[j][i].kierunek = 1;
                    pomoc[j][i].wartosc =lewo;
                }
                else
                {
                    if(j==1)
                        pomoc[j][i].kierunek = 1;
                    else
                        pomoc[j][i].kierunek = 2;
                    pomoc[j][i].wartosc = gora;
                }
            }
        }
    }

    for(int i=0;i<=y;i++)
        {for(int j=0;j<=x;j++)
            {cout << pomoc[i][j].kierunek << " ";}cout << endl;}
    cout << pomoc[y][x].wartosc << endl;

    for(int i=0;i<=y;i++)
        {for(int j=0;j<=x;j++)
            {cout << pomoc[i][j].wartosc << " ";}cout << endl;}
    cout << pomoc[y][x].wartosc << endl;

    string s;
    int q = y, w = x;
    int licznik = pomoc[y][x].wartosc;
    while(licznik>0)
    {
        //cout << pomoc[q][w].kierunek;
        if(pomoc[q][w].kierunek==3)
        {
            s = docelowy[w] + s;
            q--; w--; licznik--;
            cout << "1";
        }
        else if(pomoc[q][w].kierunek==2)
            {q--; cout << "2";}
        else if(pomoc[q][w].kierunek==1)
            {w--; cout << "3";}
    }
    cout << s << "LOL" << endl;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
       liczpodciag();
}

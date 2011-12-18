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

int liczpodciag()
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
            {cout << pomoc[i][j].wartosc << " ";}cout << endl;}
    return pomoc[y][x].wartosc;
}

void odtworz_sciezke()
{

}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        printf("%d\n",liczpodciag());
        odtworz_sciezke();
    }
}

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
    int x = docelowy.size()+1;
    int y = obecny.size()+1;

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
                pomoc[i][j].wartosc = 1 + pomoc[i-1][j-1].wartosc;
                pomoc[i][j].kierunek = 3;
            }
            else
            {
                int lewo=0,gora=0;
                gora = pomoc[i][j-1].wartosc;
                lewo = pomoc[i-1][j-1].wartosc;
                if(gora < lewo)
                {
                    pomoc[i][j].kierunek = 1;
                    pomoc[i][j].wartosc =lewo;
                }
                else
                {
                    if(j==1)
                        pomoc[i][j].kierunek = 1;
                    else
                        pomoc[i][j].kierunek = 2;
                    pomoc[i][j].wartosc = gora;
                }
            }
        }
    }

    return pomoc[x][y].wartosc;
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

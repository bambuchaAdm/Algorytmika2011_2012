#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX = 3001;

/*struct pole
{
    short wartosc;
    short kierunek;
};*/

short pomoc[MAX][MAX];
short kierunek[MAX][MAX];

void liczpodciag()
{
    string obecny;
    string docelowy;
    cin >> obecny >> docelowy;
    int x = docelowy.size();
    int y = obecny.size();

    for(int i=0;i<=x;i++)
        pomoc[i][0] = 0;
    for(int i=0;i<=y;i++)
        pomoc[0][i] = 0;

    for(int j=1;j<=y;j++)
    {
        for(int i=1;i<=x;i++)
        {
            if(obecny[j-1]==docelowy[i-1])
            {
                pomoc[j][i] = 1 + pomoc[j-1][i-1];
                kierunek[j][i] = 3;
            }
            else
            {
                int lewo=0,gora=0;
                gora = pomoc[j][i-1];
                lewo = pomoc[j-1][i];
                if(gora < lewo)
                {
                    kierunek[j][i] = 1;
                    pomoc[j][i]=lewo;
                }
                else
                {
                    if(j==1)
                        kierunek[j][i] = 1;
                    else
                        kierunek[j][i] = 2;
                    pomoc[j][i] = gora;
                }
            }
        }
    }
    cout << pomoc[y][x] << endl;

    string s;
    int q = x, w = y;
    int licznik = pomoc[y][x];
    while(licznik>0)
    {
        if(kierunek[w][q]==3)
        {
            s = docelowy[q-1] + s;
            q--; w--; licznik--;
        }
        else if(kierunek[w][q]==2)
            {q--;}
        else if(kierunek[w][q]==1)
            {w--;}
    }
    cout << s << endl;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
       liczpodciag();
}

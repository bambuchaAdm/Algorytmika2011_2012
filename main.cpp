#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX = 1001;

struct pole
{
    int wartosc;
    short int kierunek;
};

pole pomoc[MAX][MAX];

void zbieraj_diamenty()
{
    int kolumny=0, wiersze=0;
    scanf("%d %d",&kolumny,&wiersze);
    int szachownica[MAX][MAX];

    for(int i=0;i<=kolumny;i++)
        pomoc[0][i].wartosc=pomoc[0][i].kierunek=0;
    for(int i=0;i<=wiersze;i++)
        pomoc[i][0].wartosc=pomoc[i][0].kierunek=0;

    for(int i=1;i<=wiersze;i++)
        for(int j=1;j<=kolumny;j++)
            scanf("%d",&szachownica[i][j]);

    for(int i=1;i<=wiersze;i++)
        for(int j=1;j<=kolumny;j++)
        {
            int a=0,b=0;
            if(szachownica[i][j])
                pomoc[i][j].wartosc=1;
            else
                pomoc[i][j].wartosc=0;

            a = pomoc[i][j-1].wartosc;
            b = pomoc[i-1][j].wartosc;
            if(a>=b)
            {
                pomoc[i][j].wartosc+=a;
                pomoc[i][j].kierunek=1;
            }
            else
            {
                pomoc[i][j].wartosc+=b;
                pomoc[i][j].kierunek=2;
            }
        }
        cout << pomoc[wiersze][kolumny].wartosc << endl;
        string sciezka;
        for(int i=0;i<kolumny+wiersze-2;i++)
        {
            int x=kolumny, y=wiersze;
            if(pomoc[x][y].kierunek==1)
            {
                sciezka = sciezka + ">";
                x--;
            }
            else if(pomoc[x][y].kierunek==2)
            {
                sciezka = sciezka + "v";
                y--;
            }
        }
        cout << sciezka << endl;

        for(int i=0;i<=wiersze;i++)
        {
            for(int j=0;j<=kolumny;j++)
                cout << pomoc[i][j].kierunek << " ";
            cout << endl;
        }
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        zbieraj_diamenty();
    return 0;
}

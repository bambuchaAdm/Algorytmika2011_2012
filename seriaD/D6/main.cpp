#include <iostream>
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
    cin >> kolumny >> wiersze;
    int szachownica[MAX][MAX];

    for(int i=0;i<=kolumny;i++)
            pomoc[0][i].wartosc=pomoc[0][i].kierunek=0;
    for(int i=0;i<=wiersze;i++)
            pomoc[i][0].wartosc=pomoc[i][0].kierunek=0;
    for(int i=1;i<=wiersze;i++)
        for(int j=1;j<=kolumny;j++)
            cin >> szachownica[i][j];

    for(int i=1;i<=wiersze;i++)
        for(int j=1;j<=kolumny;j++)
        {
            int lewo=0,gora=0;
            if(szachownica[i][j])
                pomoc[i][j].wartosc=1;
            else
                pomoc[i][j].wartosc=0;

            gora = pomoc[i][j-1].wartosc;
            lewo = pomoc[i-1][j].wartosc;
            if(gora < lewo)
            {

                pomoc[i][j].kierunek = 1;
                pomoc[i][j].wartosc +=lewo;
            }
            else
            {
                if(j==1)
                    pomoc[i][j].kierunek = 1;
                else
                    pomoc[i][j].kierunek = 2;
                pomoc[i][j].wartosc += gora;
            }
        }
        cout << pomoc[wiersze][kolumny].wartosc << " ";
        string sciezka;
        int x=wiersze, y=kolumny;
        for(int i=0;i<kolumny+wiersze-2;i++)
        {
            if(pomoc[x][y].kierunek==1)
            {
                sciezka = "v" + sciezka;
                x--;
            }
            else if(pomoc[x][y].kierunek==2)
            {
                sciezka = ">" + sciezka;
                y--;
            }
        }
        cout << sciezka << endl;
}

int main()
{
    int z=0;
    cin >> z;
    for(int i=0;i<z;i++)
        zbieraj_diamenty();
    return 0;
}

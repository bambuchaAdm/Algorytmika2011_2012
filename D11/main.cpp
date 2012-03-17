#include <iostream>
#include <vector>

using namespace std;

struct punkt
{
    int gora;
    int lewo;
};

int szer, wys;

vector< vector<bool> > pole;
vector< vecotor<punkt> > d; //distance

void readInput()
{
    cin >> wys >> szer;
    pole.resize(wys+1,vector<int>(szer+1));
    d.resize(wys+1,vector<punkt>(szer+1));
    for(int i=0;i<=szer;i++)
        pole[0][i] = 0;
    for(int i=0;i<=wys;i++)
        pole[i][0] = 0;
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;j<=szer;j++)
        {
            char a;
            cin >> a;
            if(a=='#')
                pole[i][j] = true;
        }
    }
}

void clean()
{
    pole.clear();
}

void liczOdleglosci()
{
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;k<=szer;j++)
        {
            if(pole[i][j]==true)
            {
                d[i][j].gora = 0;
                d[i][j].lewo = 0;
            }
            else
            {
                d[i][j].gora = d[i-1][j] + 1;
                d[i][j].lewo = d[i][j-1] + 1;
            }
        }
    }
}

void liczKwadraty()
{
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;j<=szer;j++)
        {

        }
    }
}

int main()
{
    int z;
    cin >> z;
    for(int i=0;i<z;i<++)
    {
        readInput();
        liczOdleglosci();
        liczKwadraty();
        clean();
    }
    return 0;
}

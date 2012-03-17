#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct punkt
{
    int gora;
    int lewo;
};

int szer, wys;

vector< vector<bool> > pole;
vector< vector<punkt> > d; //distance

void readInput()
{
    cin >> wys >> szer;
    cin.ignore();
    pole.resize(wys+1,vector<bool>(szer+1));
    d.resize(wys+1,vector<punkt>(szer+1));
    for(int i=0;i<=szer;i++)
        d[0][i].gora = d[0][i].lewo = 0;
    for(int i=0;i<=wys;i++)
        d[i][0].gora = d[i][0].lewo = 0;
    for(int i=1;i<=wys;i++)
    {
        string wiersz;
        getline(cin,wiersz);
        //cout << wiersz << endl;
        for(int j=1;j<=szer;j++)
        {
            //cout << wiersz[j-1] << " ";
            if(wiersz[j-1]=='x')
                pole[i][j] = true;
            else
                pole[i][j] = false;
        }
        //cout << endl;
    }
}

void clean()
{
    pole.clear();
    d.clear();
}

void liczOdleglosci()
{
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;j<=szer;j++)
        {
            if(pole[i][j]==true)
            {
                d[i][j].gora = 0;
                d[i][j].lewo = 0;
            }
            else
            {
                d[i][j].gora = d[i-1][j].gora + 1;
                d[i][j].lewo = d[i][j-1].lewo + 1;
            }
        }
    }
}

punkt liczKwadraty()
{
    punkt wynik; //wykorzystam sobie strukta do przechowywania wyniku. Gora - jak duzy, lewo - ile.
    wynik.gora = wynik.lewo = 0;
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;j<=szer;j++)
        {

            int maxodl = 0;
            int k = 0;
            maxodl = min(d[i][j].gora, d[i][j].lewo);
            maxodl--;
            for(;k<=maxodl;k++)
            {
                if(!(d[i-k][j-k].gora >= maxodl - k))
                {
                    maxodl = min(d[i-k][j-k].gora,maxodl);
                }
                if(!(d[i-k][j-k].lewo >= maxodl - k))
                {
                    maxodl = min(d[i-k][j-k].lewo,maxodl);
                }
            }
            if(wynik.gora < k)
            {
                wynik.gora = k;
                wynik.lewo = 1;
            }
            if(wynik.gora == k)
                wynik.lewo++;
        }
    }
    return wynik;
}

void test()
{
    cout << "W GORE" << endl;
    for(int i=0;i<=wys;i++)
    {
        for(int j=0;j<=szer;j++)
        {
            cout << d[i][j].gora << " ";
        }
        cout << endl;
    }

    cout << "W LEWO" << endl;
    for(int i=0;i<=wys;i++)
    {
        for(int j=0;j<=szer;j++)
        {
            cout << d[i][j].lewo << " ";
        }
        cout << endl;
    }
}

void test1()
{
    for(int i=0;i<=wys;i++)
    {
        for(int j=0;j<=szer;j++)
        {
            cout << pole[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        readInput();
        //test1();
        liczOdleglosci();
        //test();
        punkt wynik = liczKwadraty();
        cout << wynik.gora << " " << wynik.lewo << endl;
        clean();
    }
    return 0;
}

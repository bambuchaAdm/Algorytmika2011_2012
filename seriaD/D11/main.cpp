/**
*   Author: Adam Piekarczyk
*   Project Title: D11 - Marchewka
*   School Year: 2011/2012
*   School: VLO Krak�w
*   Class: 1e
**/
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
vector< vector<int> > kwadrat;

void readInput()
{
    cin >> wys >> szer;
    cin.ignore();
    pole.resize(wys+10,vector<bool>(szer+10));
    d.resize(wys+10,vector<punkt>(szer+10));
    kwadrat.resize(wys+10,vector<int>(szer+10));
    for(int i=0;i<=szer;i++)
        kwadrat[0][i] = d[0][i].gora = d[0][i].lewo = 0;
    for(int i=0;i<=wys;i++)
        kwadrat[i][0] = d[i][0].gora = d[i][0].lewo = 0;
    for(int i=1;i<=wys;i++)
    {
        string wiersz;
        getline(cin,wiersz);
        for(int j=1;j<=szer;j++)
        {
            if(wiersz[j-1]=='x')
                pole[i][j] = true;
            else
                pole[i][j] = false;
        }
    }
}

void clean()
{
    pole.clear();
    d.clear();
    kwadrat.clear();
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

int min3(int a, int b, int c)
{
    int wynik = 0;
    wynik = min(a,b);
    wynik = min(wynik,c);
    return wynik;
}

void liczKwadraty()
{
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;j<=szer;j++)
        {
            kwadrat[i][j] = min3(d[i][j].gora,d[i][j].lewo,kwadrat[i-1][j-1]+1);
        }
    }
}

pair<int,int> generujWynik()
{
    pair<int,int> wynik;
    wynik.first = wynik.second = 0;
    for(int i=1;i<=wys;i++)
    {
        for(int j=1;j<=szer;j++)
        {
            if(kwadrat[i][j] > wynik.first)
            {
                wynik.first = kwadrat[i][j];
                wynik.second = 1;
            } else if(kwadrat[i][j] == wynik.first)
                wynik.second++;
        }
    }
    return wynik;
}

void test()
{
    for(int i=0;i<=wys;i++)
    {
        for(int j=0;j<=szer;j++)
        {
            cout << kwadrat[i][j] << " ";
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
        liczKwadraty();
        pair<int,int> wynik = generujWynik();
        cout << wynik.first << " " << wynik.second << endl;
        clean();
    }
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 201;

int lwierzch;
pair wierch[MAX];

void wczytaj()
{
    cin >> lwierzch;
    for(int i=0;i<lwierzch;i++)
        cin >> wierch[i].first >> wierch[i].second;
}

void trianguluj()
{
    int wynik[MAX][MAX]
    for(int i=0;i<lwierzch;i++)
        wynik[i][i]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][(i+1)%lwierzch]=0;
    for(int i=0;i<lwierzch;i++)
        wynik[i][(i+2)%lwierzch]=0;
}

int main()
{
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        wczytaj();
        trianguluj();
    }
    return 0;
}

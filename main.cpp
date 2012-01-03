#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100000;

void ustawiaj()
{
    int stan=0;
    scanf("%d",&stan);
    int kompania[MAX];
    for(int i=0;i<stan;i++)
    {
        int zolniez=0;
        scanf("%d",&zolniez);
        int indeks = (int) (upper_bound(&kompania[0],&kompania[MAX],zolniez) - &kompania[0]);

    }
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        ustawiaj();
    }
    return 0;
}

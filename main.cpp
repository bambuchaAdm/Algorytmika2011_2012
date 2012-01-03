#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100000;
const int k8=2000000001;

void ustawiaj()
{
    int stan=0;
    scanf("%d",&stan);
    int kompania[MAX]={-k8};
    for(int i=0;i<MAX;i++)
        kompania[i]=k8;
    for(int i=0;i<stan;i++)
    {
        int zolniez=0;
        scanf("%d",&zolniez);
        int indeks = (int) (upper_bound(&kompania[0],&kompania[MAX],zolniez) - &kompania[0]);
        kompania[indeks]=zolniez;
    }
    int q=1;
    while(kompania[q]!=k8)
        q++;
    printf("%d\n",stan-q);
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

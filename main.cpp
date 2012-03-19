#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1000;

int jemy()
{
    pair<int,int> tort[MAX][MAX];
    int dltortu=0;
    scanf("%d",&dltortu);
    for(int i=0;i<dltortu;i++)
        scanf("%d",&tort[i][i].second);
    for(int i=1;i<dltortu;i++)
    {
        for(int j=0;j<dltortu-i;j++)
        {
            pair<int,int> a,b;
            a.first=tort[i+j-1][j].second;
            a.second=tort[i+j-1][j].first;
            b.first=tort[i+j][j+1].second;
            b.second=tort[i+j][j+1].first;
            a.second+=tort[i+j][i+j].second;
            b.second+=tort[j][j].second;
            if(a.second>b.second)
            {
                tort[i+j][j]=a;
            }
            else
            {
                tort[i+j][j]=b;
            }
        }
    }
    return tort[dltortu-1][0].second;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0; i<z; i++)
        printf("%d\n",jemy());
    return 0;
}

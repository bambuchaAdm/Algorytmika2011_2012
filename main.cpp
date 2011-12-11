#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 5;

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
            //i+j,j
            if(tort[i+j-1][j].second>tort[i+j][j+1].second)
            {
                tort[i+j][j].first=tort[i+j-1][j].second;
                tort[i+j][j].second=tort[i+j-1][j].first;
                tort[i+j][j].second+=tort[i+j][j+1].second;
            }
            else
            {
                tort[i+j][j].first=tort[i+j][j+1].second;
                tort[i+j][j].second=tort[i+j][j+1].first;
                tort[i+j][j].second+=tort[i+j-1][j].second;
            }
        }
    }
    for(int i=0;i<MAX;i++)
        {for(int j=0;j<MAX;j++)
            cout << tort[i][j].first <<"|" << tort[i][j].second << " ";
        cout << endl;}
    return tort[dltortu-1][0].first;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0; i<z; i++)
        printf("%d",jemy());
    return 0;
}

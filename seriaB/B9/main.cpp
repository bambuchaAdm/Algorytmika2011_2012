#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void filtruj()
{
    vector<vector<int> > obrazin;
    vector<vector<int> > obrazout;
    int szer=0, wys=0, promien=0;
    scanf("%d %d %d",&szer,&wys,&promien);
    for(int i=0;i<wys;i++)
        {
            obrazin.push_back(vector<int>());
            for(int j=0;j<szer;j++)
            {
                int a=0;
                scanf("%d",&a);
                obrazin[i].push_back(a);
            }
        }
    for(int i=0;i<wys;i++)
        {
            obrazout.push_back(vector<int>());
            for(int j=0;j<szer;j++)
            {
                vector<int> mediana;
                vector<int> wartosci;
                int maxzasieg=0;
                wartosci.push_back(j);
                wartosci.push_back(i);
                wartosci.push_back(szer-j-1);
                wartosci.push_back(wys-i-1);
                sort(wartosci.begin(),wartosci.end());
                maxzasieg=wartosci.front();
                if(maxzasieg>promien)
                    maxzasieg=promien;
                if(maxzasieg==0)
                    {
                        obrazout[i].push_back(obrazin[i][j]);
                        continue;
                    }
                for(int k=i-maxzasieg;k<i+maxzasieg+1;k++)
                    for(int l=j-maxzasieg;l<j+maxzasieg+1;l++)
                        mediana.push_back(obrazin[k][l]);
                int srodek=mediana.size()/2;
                nth_element(mediana.begin(),mediana.begin()+srodek,mediana.end());
                obrazout[i].push_back(mediana[srodek]);
            }
        }
        for(int i=0;i<wys;i++)
        {
            for(int j=0;j<szer;j++)
            {
                printf("%d ",obrazout[i][j]);
            }
            printf("\n");
        }
        printf("\n");
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        filtruj();
    return 0;
}

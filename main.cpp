#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int pomoc[MAX][MAX]={{0}};

void zbieraj_diamenty()
{
    int kolumny=0, wiersze=0;
    scanf("%d %d",&kolumny,&wiersze);
    int szachownica[MAX][MAX];
    for(int i=1;i<=wiersze;i++)
        for(int j=1;j<=kolumny;j++)
            scanf("%d",&szachownica[i][j]);

    for(int i=1;i<=wiersze;i++)
        for(int j=1;j<=kolumny;j++)
        {
            int a=0,b=0;
            if(szachownica[i][j])
                pomoc[i][j]=1;
            else
                pomoc[i][j]=0;
            a = pomoc[i][j-1];
            b = pomoc[i-1][j];
            pomoc[i][j]+=max(a,b);
        }
        cout << pomoc[wiersze][kolumny] << endl;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        zbieraj_diamenty();
    return 0;
}

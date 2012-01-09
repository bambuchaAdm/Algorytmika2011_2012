#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;

void strzelaj()
{
    bool spotyka[MAX][MAX];
    bool wygrywa[MAX][MAX];
    int lmusz=0;
    scanf("%d",&lmusz);
    for(int i=0;i<lmusz;i++)
        for(int j=0;j<lmusz;j++)
            cin >> wygrywa[i][j];

    for(int i=0;i<lmusz;i++)
        spotyka[i][(i+1)%lmusz]=true;
    for(int i=2;i<lmusz;i++)
        for(int j=0;j<lmusz;j++)
        {
            int skraj=i+j;
            spotyka[i][skraj%lmusz]=false;
            for(int k=j+1;k<skraj-1;k++)
                if((wygrywa[j][k%nlmusz] || wygrywa[skraj%lmusz][k%lmusz]) && spotyka[j][k%lmusz] && spotyka[k%lmusz][skraj%lmusz])
                    spotyka[j][skraj%lmusz]=true;
        }

    vector<int> wygrani;
    for(int i=0;i<lmusz;i++)
        for(int j=0;j<lmusz;j++)
        {
            if(spotyka[i][j] && spotyka[j][i])
                if(wygrywa[i][j])
                    wygrani.push_back(i);
                else
                    wygrani.push_back(j);
        }
    printf("%d\n",wygrani.size());
    while(!wygrani.empty())
    {
        printf("%d\n",wygrani.back());
        wygrani.pop_back();
    }
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        strzelaj();
    return 0;
}

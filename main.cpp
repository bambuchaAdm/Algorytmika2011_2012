#include <iostream>

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
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        strzelaj();
    return 0;
}

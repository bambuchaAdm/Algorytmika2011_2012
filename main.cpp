#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX = 3001;

int pomoc[MAX][MAX] =  {{0}};

int liczpodciag()
{
    char obecny[MAX];
    char docelowy[MAX];
    scanf("%s %s",obecny,docelowy);

    return -1;
}

void odtworz_sciezke()
{

}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        printf("%d\n",liczpodciag());
        odtworz_sciezke();
    }
}

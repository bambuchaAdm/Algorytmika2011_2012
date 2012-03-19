#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct szczyt
{
    int numer;
    int x;
    int y;
};

void quicksort(vector<szczyt>& mapa, int b, int e)
{
    int b1 = b;
    int e1 = e;
    szczyt podzial = mapa[(b+e)/2];
    do
    {

        while(podzial.x*mapa[b1].y - mapa[b1].x*podzial.y > 0)
            b1++;
        while(podzial.x*mapa[e1].y - mapa[e1].x*podzial.y < 0)
            e1--;
        if(b1<=e1)
        {
            /*if((mapa[b1].x*mapa[e1].y - mapa[b1].y*mapa[e1].x) == 0)
            {
                if (mapa[b1].y>mapa[e1].y)
                {
                    swap(mapa[b1],mapa[e1]); e1--;b1++;
                }
                else
                {
                    e1--; b1++;
                }
            }
            else*/
            {
                if((mapa[b1].x*mapa[e1].y - mapa[b1].y*mapa[e1].x) == 0)
                {
                    if(mapa[b1].y<mapa[e1].y)
                        continue;
                }
                swap(mapa[e1],mapa[b1]);
                e1--; b1++;
            }
        }
    }   while(b1<=e1);
    if(b < e1)  quicksort(mapa, b, e1);
    if(b1 < e)  quicksort(mapa, b1, e);
}

void wczytaj()
{
    int lszczytow=0;
    scanf("%d",&lszczytow);
    vector<szczyt> mapa;
    for(int i=0;i<lszczytow;i++)
    {
        mapa.push_back(szczyt());
        mapa[i].numer=i+1;
        scanf("%d %d",&mapa[i].x,&mapa[i].y);
    }
    for(int i=0;i<mapa.size();i++)
        cout << mapa[i].numer;
    cout << endl;
    quicksort(mapa, 0, mapa.size()-1);
    for(int i=0;i<lszczytow;i++)
        printf("%d\n",mapa[i].numer);
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        wczytaj();
    }
    return 0;
}

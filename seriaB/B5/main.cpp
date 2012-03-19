#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>

using namespace std;

void tanczmy()
{
    int llewy=0, lprawy=0, czas=0;
    scanf("%d %d %d",&llewy, &lprawy, &czas);
    deque<int> lewy;
    deque<int> prawy;
    for(int i=1;i<=llewy;i++)
        lewy.push_back(i);
    for(int i=llewy+1;i <= lprawy+llewy;i++)
        prawy.push_back(i);

    int lzmian=0;
    scanf("%d",&lzmian);

    queue<int> zmiany;
    for(int i=0;i<lzmian;i++)
    {
        int a=0;
        scanf("%d",&a);
        zmiany.push(a);
    }

    int zost=0;
    int znast=0;
    int czastera=0;
    bool kier=true;
    int zmiana=0;
    bool war=false;

    while(czastera!=czas)
    {
        if(!zmiany.empty())
            {znast=zmiany.front(); zmiany.pop();}
        else
            {znast=czas; war=true;}
        for(int i=0;i<znast-zost;i++)
            if(kier)
            {
                lewy.push_back(lewy.front()); lewy.pop_front();
                prawy.push_back(prawy.front()); prawy.pop_front();
                zmiana++;
            }
            else
            {
                lewy.push_front(lewy.back()); lewy.pop_back();
                prawy.push_front(prawy.back()); prawy.pop_back();
                zmiana--;
            }
        if(war)
            break;
        czastera+=znast-zost;
        int a=lewy.front(); lewy.pop_front();
        lewy.push_front(prawy.front()); prawy.pop_front();
        prawy.push_front(a);
        kier=!kier;
        zost=znast;
    }
    int zmianal=zmiana%llewy;
    zmiana = zmiana%lprawy;

    if(zmianal>0)
        while(zmianal!=0)
        {
            lewy.push_front(lewy.back()); lewy.pop_back();
            zmianal--;
        }
    else
        while(zmianal!=0)
        {
            lewy.push_back(lewy.front()); lewy.pop_front();
            zmianal++;
        }
    if(zmiana>0)
        while(zmiana!=0)
        {
            prawy.push_front(prawy.back()); prawy.pop_back();
            zmiana--;
        }
    else
        while(zmiana!=0)
        {
            prawy.push_back(prawy.front()); prawy.pop_front();
            zmiana++;
        }
    while(!lewy.empty())
    {
        printf("%d ",lewy.front()); lewy.pop_front();
    }
    while(!prawy.empty())
    {
        printf("%d ",prawy.front()); prawy.pop_front();
    }
    printf("\n");
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        tanczmy();
    }
    return 0;
}

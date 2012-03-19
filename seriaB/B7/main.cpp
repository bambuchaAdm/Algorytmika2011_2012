#include <cstdio>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

set<int> unikaty;
multiset<int> oceny;
multiset<int> dolnasr;
multiset<int> gornasr;

void skroc(int licz, int mian)
{
    int c=0;
    int a=licz;
    int b=mian;
    while (b != 0)
    {
          c = a % b;
          a = b;
          b = c;

    }
    if(a!=1)
    {
        licz/=a;
        mian/=a;
    }
    printf("%d/%d ",licz,mian);
}

void dolnasredniaiden()
{
    printf("%d/1 ",*unikaty.begin());
}

void gornasredniaiden()
{
    printf("%d/1 ",*unikaty.begin());
}

void gornasrednia(int srednia)
{
    multiset<int> ocenycopy = oceny;
    set<int>::reverse_iterator ritbeg;
    ritbeg=ocenycopy.rbegin();
    while(ritbeg!=ocenycopy.rend())
    {
        if((*ritbeg)>srednia)
        {
            pair <set<int>::iterator,set<int>::iterator> zasieg;
            zasieg=ocenycopy.equal_range(*ritbeg);
            if(zasieg.second!=ocenycopy.end()||(zasieg.second==ocenycopy.end()&&zasieg.first!=ocenycopy.end()))
            {
                set<int>::iterator spraw = zasieg.first;
                spraw--;
                for(set<int>::iterator it=zasieg.first; it!=zasieg.second;it++)
                {
                    gornasr.insert(*it);
                    ocenycopy.erase(it);
                    if(*spraw!=*it)
                        break;
                    spraw++;
                }
            int sumael=0;
            for(set<int>::iterator it=gornasr.begin();it!=gornasr.end();it++)
            {
                sumael+=(*it);
            }
            srednia=ceil(sumael/gornasr.size());
            ritbeg=ocenycopy.rbegin();
            continue;}
        }
        ritbeg++;
    }
    int sumael=0;
    for(set<int>::iterator it=gornasr.begin();it!=gornasr.end();it++)
    {
        sumael+=(*it);
    }
    skroc(sumael, gornasr.size());
    printf("\n");
}

void dolnasrednia(int srednia)
{
    multiset<int> ocenycopy = oceny;
    set<int>::iterator itbeg;
    itbeg=ocenycopy.begin();
    while(itbeg!=ocenycopy.end())
    {
        if((*itbeg)<=srednia)
        {
            pair <set<int>::iterator,set<int>::iterator> zasieg;
            zasieg=ocenycopy.equal_range(*itbeg);
            for(set<int>::iterator it=zasieg.first; *it< *zasieg.second;it++)
            {
                dolnasr.insert(*it);
                ocenycopy.erase(it);
            }
            int sumael=0;
            for(set<int>::iterator it=dolnasr.begin();it!=dolnasr.end();it++)
            {
                sumael+=(*it);
            }
            srednia=floor(sumael/dolnasr.size());
            itbeg=ocenycopy.begin();
            continue;
        }
        itbeg++;
    }
    int sumael=0;
    for(set<int>::iterator it=dolnasr.begin();it!=dolnasr.end();it++)
    {
        sumael+=(*it);
    }
    skroc(sumael, dolnasr.size());
}

void srednia()
{
    unikaty.clear();
    oceny.clear();
    dolnasr.clear();
    gornasr.clear();
    int locen=0;
    scanf("%d",&locen);
    int ost=0;
    bool war=true;
    for(int i=0;i<locen;i++)
    {
        int a=0;
        scanf("%d",&a);
        if(i==0)
            ost=a;
        if(ost!=a)
            war=false;
        unikaty.insert(a);
        oceny.insert(a);
        ost=a;
    }
    for(set<int>::iterator it=unikaty.begin();it!=unikaty.end();it++)
    {
        oceny.erase(oceny.find(*it));
    }
    int sumael=0;
    for(set<int>::iterator it=unikaty.begin();it!=unikaty.end();it++)
    {
        sumael+=(*it);
        dolnasr.insert(*it);
        gornasr.insert(*it);
    }
    int srednia=0;
    int srednia1=0;
    srednia=floor(sumael/unikaty.size());
    srednia1=ceil(sumael/unikaty.size());
    if(war)
    {
        dolnasredniaiden();
        gornasredniaiden();
    }
    else
    {
        dolnasrednia(srednia);
        gornasrednia(srednia1);
    }
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        srednia();
    return 0;
}

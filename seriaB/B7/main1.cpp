#include <set>
#include <queue>
//#include <cstdio>
#include <iostream>

using namespace std;

set<long long> unikaty;
priority_queue<long long> ocenygora;
priority_queue<long long> ocenydol;
multiset<long long> dolnasr;
multiset<long long> gornasr;

void skroc(long long licz, long long mian)
{
    long long c=0;
    long long a=licz;
    long long b=mian;
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
    //printf("%d/%d ",licz,mian);
    cout << licz << "/" << mian << " ";
}

void sredniaiden()
{
    //printf("%d/1 ",*unikaty.begin());
    cout << *unikaty.begin() << "/" << "1" << " ";
}

void gornasrednia(long long srednia, long long sumael)
{
    set<long long>ugora = unikaty;
    while(ocenygora.top()>=srednia)
    {
        if(ocenygora.top()==*ugora.rbegin())
            {
                ocenygora.pop(); ugora.erase(*ugora.rbegin());  continue;
            }
        gornasr.insert(ocenygora.top());
        sumael+=(ocenygora.top());
        ocenygora.pop();
        srednia=sumael/gornasr.size()+1;
    }
    skroc(sumael, gornasr.size());
    //printf("\n");
    cout << endl;
}

void dolnasrednia(long long srednia, long long sumael)
{
    set<long long>udol = unikaty;
    while(-(ocenydol.top())<=srednia)
    {
        if(-ocenydol.top()==*udol.begin())
            {
                ocenydol.pop(); udol.erase(*udol.begin());  continue;
            }
        dolnasr.insert(-ocenydol.top());
        sumael+=(-ocenydol.top());
        ocenydol.pop();
        srednia=sumael/dolnasr.size();
    }
    skroc(sumael, dolnasr.size());
}

void srednia()
{
    unikaty.clear();
    dolnasr.clear();
    gornasr.clear();
    while(!ocenygora.empty())
        ocenygora.pop();
    while(!ocenydol.empty())
        ocenydol.pop();
    long long locen=0;
    //scanf("%d",&locen);
    cin >> locen;
    long long ost=0;
    bool war=true;
    for(long long i=0;i<locen;i++)
    {
        long long a=0;
        //scanf("%d",&a);
        cin >> a;
        if(i==0)
            ost=a;
        if(ost!=a)
            war=false;
        unikaty.insert(a);
        ocenydol.push(-a);
        ocenygora.push(a);
        ost=a;
    }
    long long sumael=0;
    for(set<long long>::iterator it=unikaty.begin();it!=unikaty.end();it++)
    {
        sumael+=(*it);
        dolnasr.insert(*it);
        gornasr.insert(*it);
    }
    long long sumael1=sumael;
    long long srednia=0;
    long long srednia1=0;
    srednia=sumael/unikaty.size();
    srednia1=sumael/unikaty.size()+1;
    if(war)
    {
        sredniaiden();
        sredniaiden();
        //printf("\n");
        cout << endl;
    }
    else
    {
        dolnasrednia(srednia, sumael);
        gornasrednia(srednia1,sumael1);
    }
}

int main()
{
    long long z=0;
    //scanf("%d",&z);
    cin >> z;
    for(long long i=0;i<z;i++)
        srednia();
    return 0;
}

#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

int ilebitow()
{
    priority_queue<int> Q;
    int wynik=0;
    int ileslow=0;
    scanf("%d",&ileslow);
    for(int i=0;i<ileslow;i++)
    {
        int a=0;
        scanf("%d",&a);
        Q.push(-a);
    }
    while(Q.size()!=1)
    {
        int a=Q.top(); Q.pop();
        int b=Q.top(); Q.pop();
        wynik+=-(a+b);
        Q.push(a+b);
    }
    return wynik;
}

int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        cout <<ilebitow() << endl;
    return 0;
}

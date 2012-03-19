#include <cstdio>
#include <stack>

using namespace std;

void czarujemy()
{
    stack<int> czary;
    int lzaklec=0;
    scanf("%d",&lzaklec);
    for(int i=0;i<lzaklec;i++)
    {
        int a;
        scanf("%d",&a);
        if(i==0)
        {
            czary.push(a);
            continue;
        }
        if(!czary.empty())
        {
            if(czary.top()==a)
            {
                czary.pop();
                continue;
            }
            else
            {
                czary.push(a);
                continue;
            }
        }
        else
        {
            printf("TAK\n");
            return;
        }
    }
    if(!czary.empty())
        printf("NIE\n");
    else
        printf("TAK\n");
}

int main()
{
    int z =0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
        czarujemy();
    return 0;
}

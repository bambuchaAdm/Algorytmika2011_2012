#include <cstdio>
#include <queue>

using namespace std;

void wojna()
{
 int lkartA=0;
 int lkartB=0;
 queue<int> A;
 queue<int> B;
 scanf("%d",&lkartA);
 for(int i=0;i<lkartA;i++)
 {
 int a=0;
 scanf("%d",&a);
 A.push(a);
 }
 scanf("%d",&lkartB);
 for(int i=0;i<lkartB;i++)
 {
 int a=0;
 scanf("%d",&a);
 B.push(a);
 }
 int dlwojny=0;
 scanf("%d",&dlwojny);
 for(int i=0;i<dlwojny;i++)
 {
  if(A.front()>B.front())
  {
   A.push(B.front());
   A.push(A.front());
   A.pop();
   B.pop();
   if(B.empty())
   {
    printf("A wygrywa w turze %d.\n",i+1); return;
   }
  }
  else
  {
   B.push(A.front());
   B.push(B.front());
   A.pop();
   B.pop();
   if(A.empty())
   {
    printf("B wygrywa w turze %d.\n",i+1); return;
   }
  }
 }
 printf("A: ");
 while(!A.empty())
  {printf("%d ",A.front()); A.pop();}
 printf("\n");
 printf("B: ");
 while(!B.empty())
  {printf("%d ",B.front()); B.pop();}
 printf("\n");
}

int main()
{
 int z=0;
 scanf("%d",&z);
 for(int i=0;i<z;i++)
 wojna();
 return 0;
}

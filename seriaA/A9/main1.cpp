#include <iostream>
#include <string>

using namespace std;

void mnoz(string x, string y)
{
     int minus1 = 0;
     int minus2 = 0;

     if(x[0]=='-')
     {
      minus1 = 1;
      x.erase(0,1);
     }
     if(y[0]=='-')
     {
      minus2 = 1;
      y.erase(0,1);
     }

     int wieksza=0;
     int mniejsza=0;
     if(x.size()>=y.size())
     {
      wieksza=x.size();
      mniejsza=y.size();
     }
     else
     {
      wieksza=y.size();
      mniejsza=x.size();
     }
    int dod1[5005]={0};
    int dod2[5005]={0};
     //int *dod1 = new int[wieksza];
     //for(int i=0;i<wieksza;i++)
        //dod1[i]=0;
     //int *dod2 = new int[mniejsza];
     //for(int i=0;i<mniejsza;i++)
       // dod2[i]=0;
     if(x.size()>=y.size())
     {
     for(int i=0;i<wieksza;i++)
      dod1[i]=x[i]-'0';
     for(int i=0;i<mniejsza;i++)
      dod2[i]=y[i]-'0';
     }
     else
     {
     for(int i=0;i<mniejsza;i++)
      dod2[i]=x[i]-'0';
     for(int i=0;i<wieksza;i++)
      dod1[i]=y[i]-'0';
     }

     int wynik[10000]={0};
     int suma[10000]={0};

     for(int i=0;i<mniejsza;i++)
     {
       for(int j=0;j<wieksza;j++)
        suma[j]=0;
       for(int j=0;j<wieksza;j++)
       {
        suma[j]=dod1[j]*dod2[mniejsza-1-i];
       }
       int przen=0;
       for(int j=0;j<wieksza;j++)
       {
            wynik[mniejsza+wieksza-1-i-j]+=suma[wieksza-1-j];
       }
       for(int j=0;j<wieksza+mniejsza-1;j++)//
       {
           if(wynik[mniejsza+wieksza-1-i-j]>=10)
           {
               przen=wynik[mniejsza+wieksza-1-i-j]/10;
               wynik[mniejsza+wieksza-1-i-j]=wynik[mniejsza+wieksza-1-i-j]%10;
                         wynik[mniejsza+wieksza-2-i-j]+=przen;
           }
       }

     }

     if(wieksza==1&&dod1[0]==0)
              {cout << "0" <<endl; return;}

      if(mniejsza==1&&dod2[0]==0)
              {cout << "0" <<endl; return;}

     if(minus1^minus2)
        cout <<"-";

      bool war=true;
     for(int i=0;i<wieksza+mniejsza;i++)
     {
      if(war&&wynik[i]!=0)
      {war=false;}
      if(war)
      {continue;}
      else
      {cout << wynik[i];}
     }
     cout << endl;

    /* delete [] dod1;
     dod1=NULL;
     delete [] dod2;
     dod2=NULL;*/
}

int main()
{
    int z=0;
    cin >> z;
    for(int i=0;i<z;i++)
    {
            string a="";
            string b="";
            cin >> a;
            cin >> b;
            mnoz(a,b);
    }
    return 0;
}

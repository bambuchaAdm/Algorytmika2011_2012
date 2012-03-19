#include <iostream>
#include <string>

using namespace std;

void mnoz(string x, string y)
{
     bool minus1 = false;
     bool minus2 = false;
     //short wynik[10000] = {0};
     //short suma[10000] = {0};

     if(x[0]=='-')
     {
      minus1 = true;
      x.erase(0,1);
     }
     if(y[0]=='-')
     {
      minus2 = true;
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

     int *dod1 = new int[wieksza];
     for(int i=0;i<wieksza;i++)
        dod1[i]=0;
     int *dod2 = new int[mniejsza];
     for(int i=0;i<mniejsza;i++)
        dod2[i]=0;
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

     int *wynik = new int[wieksza+mniejsza];
     for(int i=0;i<wieksza+mniejsza;i++)
        wynik[i]=0;
     int *suma = new int[wieksza];
     for(int i=0;i<wieksza;i++)
        suma[i]=0;

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

     if(minus1^minus2)
        cout <<"-";

     for(int i=0;i<wieksza+mniejsza;i++)
      cout << wynik[i] << " ";
     cout << endl;

     delete [] dod1;

     dod1=NULL;

     delete [] dod2;

     dod2=NULL;

     delete [] wynik;

     wynik=NULL;

     delete [] suma;

     suma=NULL;
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

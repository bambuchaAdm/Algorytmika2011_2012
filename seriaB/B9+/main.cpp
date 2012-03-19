#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void wypisz(vector<vector<int> >& obrazout, int wys, int szer)
{
    for(int i=0;i<wys;i++)
        {
            for(int j=0;j<szer;j++)
            {
                printf("%d ",obrazout[i][j]);
            }
            printf("\n");
        }
        printf("\n");
}

int wyznacz_pixel(int (&kolory)[256], int promien)
{
    int indeksmed=((2*promien+1)*(2*promien+1)+1)/2;
    int suma=0;
    int i=0;
    while(suma<indeksmed)
    {
        suma+=kolory[i];
        i++;
    }
    return i-1;
}

void filtruj_rowne(vector<vector<int> >& obrazin, vector<vector<int> >& obrazout, int szer, int wys, int promien)
{
    int zakresx=szer-1-promien;
    int zakresy=wys-1-promien;
    if(zakresx<promien || zakresy<promien)
        return;
    for(int i=promien;i<=zakresx;i++)
    {
        int kolory[256]={0};
        for(int j=promien;j<=zakresy;j++)
        {
            if(j==promien)
                for(int z=i-promien;z<=i+promien;z++)
                    for(int o=j-promien;o<=j+promien;o++)
                        {kolory[obrazin[z][o]]++;}
            else
                for(int z=i-promien;z<=i+promien;z++)
                    {kolory[obrazin[z][j+promien]]++;}
            obrazout[i][j]=wyznacz_pixel(kolory,promien);
            for(int z=i-promien;z<=i+promien;z++)
                    {kolory[obrazin[z][j-promien]]--;}
        }
    }
}

void filtruj(vector<vector<int> >& obrazin, vector<vector<int> >& obrazout, int szer, int wys, int promien)
{
    for(int i=1;i<promien;i++)
    {
        int kolory[256]={0};
        for(int z=0;z<=2*i;z++)
            for(int o=0;o<=2*i;o++)
                {kolory[obrazin[z][o]]++;}
        int n=i;
        obrazout[i][i]=wyznacz_pixel(kolory,i);
        n++;
        int n2=n;
        for(int n1=n;n1<szer-i;n1++)
        {
            for(int z=0;z<n+i;z++)
                {kolory[obrazin[z][n1-i-1]]--;}
            for(int z=0;z<n+i;z++)
                {kolory[obrazin[z][n1+i]]++;}
            if(n1==szer-i-1)
            {for(int q=0;q<10;q++)
                cout << kolory[q] << " ";
            cout << endl << endl;}
            obrazout[i][n1]=wyznacz_pixel(kolory,i);
            n2++;
        }

    }
}
int main()
{
    int z=0;
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        vector<vector<int> > obrazin;
        vector<vector<int> > obrazout;
        int szer=0, wys=0, promien=0;
        scanf("%d %d %d",&szer,&wys,&promien);
        for(int i=0;i<wys;i++)
        {
            obrazin.push_back(vector<int>());
            obrazout.push_back(vector<int>());
            for(int j=0;j<szer;j++)
            {
                int a=0;
                scanf("%d",&a);
                obrazin[i].push_back(a);
                obrazout[i].push_back(int());
                if(i==0)
                    {obrazout[i][j]=a; continue;}
                if(j==0)
                    {obrazout[i][j]=a; continue;}
                if(i==wys-1)
                    {obrazout[i][j]=a; continue;}
                if(j==szer-1)
                    {obrazout[i][j]=a; continue;}
            }
        }
        filtruj_rowne(obrazin,obrazout,szer,wys,promien);
        filtruj(obrazin,obrazout,szer,wys,promien);
        wypisz(obrazout,wys,szer);
    }
    return 0;
}

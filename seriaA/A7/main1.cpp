#include <string>
#include <iostream>

using namespace std;

void dodawanie(string a, string b)
{
    int dlugoscA=a.size();      //ustalam dlugosci obu skladnikow sumy
    int dlugoscB=b.size();
    int dluzszy=0;

    if(dlugoscA>=dlugoscB)  //sprawdzam, ktory jest wiekszy, w ten sposob ustalajac maksymalna dlugosc tablicy. Uwzgledniam dodatkowe miejsce na przeniesienie jedynki na samym poczatku.
        dluzszy=dlugoscA+1;
    else
        dluzszy=dlugoscB+1;

    int *A = new int[dluzszy];
    int *B = new int[dluzszy];

    for(int i=0;i<dluzszy;i++)
    {
        A[i]=0;
        B[i]=0;
    }

    for(int i=0;i<a.size();i++)        //wydzielam poszczegolne cyferki ze strigow i ukladam je w tablicach
    {
            A[dluzszy-1-i]=int(a[dlugoscA-1-i]-'0');
    }
    for(int i=0;i<b.size();i++)
    {
            B[dluzszy-1-i]=int(b[dlugoscB-1-i]-'0');
    }
    int wynik=0;
    int przen=0;
    for(int i=dluzszy-1;i>=0;i--)       //dodajemy od tylu cyfry i bierzemy poprawke na przeniesienie
    {
        wynik=0;
        wynik=A[i]+B[i]+przen;
        if(wynik>9)
            przen=1;
        else
            przen=0;
        A[i]=(wynik%10);
    }
    for(int i=0;i<dluzszy;i++)
    {
        if(A[0]==0&&i==0) continue; //dbamy o to, zeby nam zero na poczatku nie wyskoczylo i wypisujemy liczbe.
        cout << A[i];
    }
    cout << endl;
    delete [] A;
    delete [] B;
    A = NULL;
    B = NULL;
}


int main()
{
    int z=0;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        string a;
        string b;
        cin >> a;
        cin >> b;
        dodawanie(a,b);
    }
    return 0;
}

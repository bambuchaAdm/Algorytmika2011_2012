#include <iostream>
#include <vector>

using namespace std;

vector<int> kompania;
long long bledy;

void merge(int po, int sr, int kon)
{
    vector<int> pomoc;
    pomoc=kompania;
    int i, j, q;
    i = po; j= sr+1; q = po;
    while(i<=sr && j<=kon)
        if(pomoc[i]>pomoc[j])
            {kompania[q]=pomoc[i];q++;i++;}
        else
            {kompania[q]=pomoc[j];bledy+=(sr-i+1);q++;j++;}
    while(i<=sr)
        {kompania[q]=pomoc[i]; q++; i++;}
}

void mergesort(int b, int e)
{
    if(b<e)
    {
        int podzial=(b+e)/2;
        mergesort(b,podzial);
        mergesort(podzial+1,e);
        merge(b,podzial,e);
    }

}

void ustaw()
{
    bledy=0;
    kompania.clear();
    int stan=0;
    cin >> stan;
    for(int i=0;i<stan;i++)
    {
        int a;
        cin >> a;
        kompania.push_back(a);
    }
    mergesort(0,kompania.size()-1);
    for(int i=0;i<kompania.size();i++)
        cout << kompania[i] << " ";
    cout << endl << bledy << endl;
}

int main()
{
    int z=0;
    cin >> z;
    for(int i=0;i<z;i++)
        ustaw();
    return 0;
}

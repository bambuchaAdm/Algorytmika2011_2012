#include <cstdio>
#include <map>
#include <string>

using namespace std;

void turniej()
{
    map<string,string> zawodnicy;
    int dlugosc=0;
    scanf("%d",&dlugosc);
    for(int i=0;i<dlugosc;i++)
    {
        string imie;
        scanf("%s",&imie);
        if(zawodnicy["imie"]=="")
            zawodnicy["imie"]='-';
        else

    }


}

int main()
{
    int z=0;
    scanf("%d",z);
    for(int i=0;i<z;i++)
        turniej();
    return 0;
}

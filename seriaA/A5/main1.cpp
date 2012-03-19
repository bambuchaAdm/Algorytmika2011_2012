#include <iostream>
#include <string>
#include <cctype>

using namespace std;



int rometodec(string zamiana)
{
    size_t znalezione; //TYP zmiennej zdefiniowany w cctype, ktora jest bezznakowym integralnym typem. Uzywane jako zwrot funkcji typu sizeof. Znaleznione w opisie biblioteki, nie powiem zebym kminil;p
    int wynik=0;
    string dziesiatki[] = {"MM","CM","M","DCCC","DCC","DC","CD","D","CCC","CC","XC","C","LXXX","LXX","LX","XL","L","XXX","XX","IX","X","VIII","VII","VI","IV","V","III","II","I"};
for(int i=0;i<29;i++)
    {
        znalezione=zamiana.find(dziesiatki[i]);
        if(znalezione!=string::npos)
        {
            switch(i)
            {
                case 0:
                    wynik+=2000;
                    zamiana.erase(0,2);
                    break;
                case 1:
                    wynik+=900;
                    zamiana.erase(int(znalezione),2);
                    break;
                case 2:
                    wynik+=1000;
                    zamiana.erase(0,1);
                    break;
                case 3:
                    wynik+=800;
                    zamiana.erase(0,4);
                    break;
                case 4:
                    wynik+=700;
                    zamiana.erase(0,3);
                    break;
                case 5:
                    wynik+=600;
                    zamiana.erase(0,2);
                    break;
                case 6:
                    wynik+=400;
                    zamiana.erase(0,2);
                    break;
                case 7:
                    wynik+=500;
                    zamiana.erase(0,1);
                    break;
                case 8:
                    wynik+=300;
                    zamiana.erase(0,3);
                    break;
                case 9:
                    wynik+=200;
                    zamiana.erase(0,2);
                    break;
                case 10:
                    wynik+=90;
                    zamiana.erase(int(znalezione),2);
                    break;
                case 11:
                    wynik+=100;
                    zamiana.erase(0,1);
                    break;
                case 12:
                    wynik+=80;
                    zamiana.erase(0,4);
                    break;
                case 13:
                    wynik+=70;
                    zamiana.erase(0,3);
                    break;
                case 14:
                    wynik+=60;
                    zamiana.erase(0,2);
                    break;
                case 15:
                    wynik+=40;
                    zamiana.erase(0,2);
                    break;
                case 16:
                    wynik+=50;
                    zamiana.erase(0,1);
                    break;
                case 17:
                    wynik+=30;
                    zamiana.erase(0,3);
                    break;
                case 18:
                    wynik+=20;
                    zamiana.erase(0,2);
                    break;
                case 19:
                    wynik+=9;
                    zamiana.erase(int(znalezione),2);
                    break;
                case 20:
                    wynik+=10;
                    zamiana.erase(0,1);
                    break;
                case 21:
                    wynik+=8;
                    zamiana.erase(0,4);
                    break;
                case 22:
                    wynik+=7;
                    zamiana.erase(0,3);
                    break;
                case 23:
                    wynik+=6;
                    zamiana.erase(0,2);
                    break;
                case 24:
                    wynik+=4;
                    zamiana.erase(0,2);
                    break;
                case 25:
                    wynik+=5;
                    zamiana.erase(0,1);
                    break;
                case 26:
                    wynik+=3;
                    zamiana.erase(0,3);
                    break;
                case 27:
                    wynik+=2;
                    zamiana.erase(0,2);
                    break;
                case 28:
                    wynik+=1;
                    zamiana.erase(0,1);
                    break;
            }
        }
    }
    return wynik;
}

string dectorome(string zamiana)
{
    string wynik;
    int licznik=0;
    licznik=zamiana.size();
    int a=0; int b=0; int c=0; int d=0;
    if(licznik>=1)
        a=zamiana[zamiana.size()-1]-'0';
    if(licznik>=2)
        b=zamiana[zamiana.size()-2]-'0';
    if(licznik>=3)
        c=zamiana[zamiana.size()-3]-'0';
    if(licznik>=4)
        d=zamiana[zamiana.size()-4]-'0';
    switch(a)
    {
        case 1:
            wynik=wynik+"I";
            break;
        case 2:
            wynik=wynik+"II";
            break;
        case 3:
            wynik=wynik+"III";
            break;
        case 4:
            wynik=wynik+"IV";
            break;
        case 5:
            wynik=wynik+"V";
            break;
        case 6:
            wynik=wynik+"VI";
            break;
        case 7:
            wynik=wynik+"VII";
                break;
        case 8:
            wynik=wynik+"VIII";
                break;
        case 9:
            wynik=wynik+"IX";
            break;
        case 0:
            break;
    }
    switch(b)
    {
        case 1:
            wynik="X"+wynik;
            break;
        case 2:
            wynik="XX"+wynik;
            break;
        case 3:
            wynik="XXX"+wynik;
            break;
        case 4:
            wynik="XL"+wynik;
            break;
        case 5:
            wynik="L"+wynik;
            break;
        case 6:
            wynik="LX"+wynik;
            break;
        case 7:
            wynik="LXX"+wynik;
                break;
        case 8:
            wynik="LXXX"+wynik;
                break;
        case 9:
            wynik="XC"+wynik;
            break;
        case 0:
            break;
    }
    switch(c)
    {
        case 1:
            wynik="C"+wynik;
            break;
        case 2:
            wynik="CC"+wynik;
            break;
        case 3:
            wynik="CCC"+wynik;
            break;
        case 4:
            wynik="CD"+wynik;
            break;
        case 5:
            wynik="D"+wynik;
            break;
        case 6:
            wynik="DC"+wynik;
            break;
        case 7:
            wynik="DCC"+wynik;
                break;
        case 8:
            wynik="DCCC"+wynik;
                break;
        case 9:
            wynik="CM"+wynik;
            break;
        case 0:
            break;
    }
    switch(d)
    {
        case 1:
            wynik="M"+wynik;
            break;
        case 2:
            wynik="MM"+wynik;
            break;
        case 0:
            break;
    }
    return wynik;
}

int main()
{
    int Z=0;
    cin >> Z;
    for(int i=0;i<Z;i++)
    {
        string zamiana = "";
        cin >> zamiana;
        if(isalpha(zamiana[0]))
            cout << rometodec(zamiana)<<endl;
        else
            cout << dectorome(zamiana)<<endl;
    }
    return 0;
}

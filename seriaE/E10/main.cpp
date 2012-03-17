/**
*   Author: Adam Piekarczyk
*   Project Title: E10 - Fikuslandia
*   School Year: 2011/2012
*   School: VLO Krak�w
*   Class: 1e
**/

#include <iostream>
#include <vector>

using namespace std;

const int BIALY = 1;
const int SZARY = 2;
const int CZARNY = 3;
const int BRAK = -1;

int vertices, edges;
int czas = 0;

vector<vector<int> > graf;
vector<int> kolor;
vector<int> pre;    //order
vector<int> in;
vector<int> post;
vector<int> lewy;
vector<int> prawy;
vector<int> parent;

void readInput()
{
    cin >> vertices;
    edges = vertices - 1;
    const int MAX = vertices + 1;
    graf.resize(MAX);
    pre.resize(MAX);
    in.resize(MAX);
    post.resize(MAX);
    lewy.resize(MAX);
    prawy.resize(MAX);
    parent.resize(MAX);
    kolor.resize(MAX,BIALY);
    for(int i=0;i<edges;i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
}

void clean()
{
    graf.clear();
    kolor.clear();
    pre.clear();
    in.clear();
    post.clear();
}

void test()
{

}

int ukorzen()
{
    for(int i=1;i<vertices;i++)
    {
        if(graf[i].size() < 3)
            return i;
    }
}

void visitVertex(int n)
{
    czas++;
    pre[n]=czas;
    kolor[n]=SZARY;
    bool war = false;
    for(int i=0;i<graf[n].size();i++)
    {
        if(kolor[graf[n][i]]==BIALY)
        {
            parent[graf[n][i]] = n;
            if(!war)
                lewy[n] = graf[n][i];
            if(war)
            {
                czas++;
                in[n] = czas;
                prawy[n] = graf[n][i];
            }
            war = true;
            visitVertex(graf[n][i]);
        }
    }
    kolor[n]=CZARNY;
    czas++;
    post[n] = czas;
}

void DFS(int n)
{
    czas = 0;
    visitVertex(n);
}

int main()
{
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        readInput();
        int korzen = ukorzen();
        przodek[korzen] = BRAK;
        DFS(korzen);
        printOutput();
        //test();
        clean();
    }
}

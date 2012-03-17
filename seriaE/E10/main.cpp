/**
*   Author: Adam Piekarczyk
*   Project Title: E10 - Fikuslandia
*   School Year: 2011/2012
*   School: VLO Kraków
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
int time = 0;

vector<vector<int> > graf;
vector<int> kolor;
vector<int> pre;    //order
vector<int> in;
vector<int> post;
vector<int> lewy;
vector<int> prawy;
vector<int> przodek;

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
    przodek.resize(MAX);
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
        if(graf[i].size < 3)
            return i;
    }
}

void visitVertex(int n)
{
    time++;
    pre[n]=time;
    kolor[n]=SZARY;
    bool war = false;
    for(int i=0;i<graf[n].size();i++)
    {
        if(kolor[graf[n][i]]==BIALY)
        {

        }
    }
}

void DFS(int n)
{
    time = 0;
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

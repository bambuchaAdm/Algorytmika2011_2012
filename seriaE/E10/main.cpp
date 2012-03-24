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
    cerr << "READ INPUT DONE" << endl;
}

void clean()
{
    graf.clear();
    kolor.clear();
    pre.clear();
    in.clear();
    post.clear();
    lewy.clear();
    prawy.clear();
    parent.clear();
    cerr << "CLEAN DONE" << endl;
}

void test()
{
    //for(int i=1;i<=vertices;i++)
    //    cout << parent[i] << " ";
    //cout << endl;
    for(int i=1;i<=vertices;i++)
    {
        cout << pre[i] << " " << in[i] << " " << post[i] << endl;
    }
}

int ukorzen()
{
    for(int i=1;i<=vertices;i++)
    {
        if(graf[i].size() < 3)
            return i;
    }
    cerr << "UKORZEN DONE" << endl;
}

void visitVertex(int n)
{
    czas++;
    pre[n]=czas;
    kolor[n]=SZARY;
    bool war = false;
    if(graf[n].size()==1)
    {
        czas++;
        in[n] = czas;
    }
    else
    {
        int i=0;
        if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
        {
            lewy[n]=graf[n][i];
            visitVertex(graf[n][i]);
            i++;
            war = true;
        }
        else
        {
            i++;
        }
        if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
        {
            if(!war)
                lewy[n]=graf[n][i];
            else
            {
                czas++;
                in[n]=czas;
                prawy[n]=graf[n][i];
            }
            visitVertex(graf[n][i]);
            i++;
            war = true;
        }
        else
        {
            i++;
        }
        if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY && graf[n].size()>2)
        {
            if(!war)
                lewy[n]=graf[n][i];
            else
            {
                czas++;
                in[n]=czas;
                prawy[n]=graf[n][i];
            }
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
    cerr << "DFS DONE" << endl;
}

void generujDroge(int z, int cel)
{
    cout << z << " ";
    if(z==cel)
        return;
    if(pre[cel] >= pre[z] && post[cel] <= post[z])
    {
        if(in[cel] <= in[z])
        {
            generujDroge(lewy[z],cel);
        }
        else
        {
            generujDroge(prawy[z],cel);
        }
    }
    else
    {
        generujDroge(parent[z],cel);
    }
    cerr << "GENERUJ DROGE DONE" << endl;
}

void readQuery()
{
    int query;
    cin >> query;
    for(int i=0;i<query;i++)
    {
        int z, cel;
        cin >> z >> cel;
        //generujDroge(z,cel);
        cout << endl;
    }
    cerr << "READ QUERY DONE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        readInput();
        int korzen = ukorzen();
        parent[korzen] = BRAK;
        DFS(korzen);
        test();
        //readQuery();
        clean();
    }
}

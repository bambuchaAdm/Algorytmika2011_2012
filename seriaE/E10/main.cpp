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

const bool TESTUJ = false;

enum kolorek
{
    BIALY = 1,
    SZARY = 2,
    CZARNY = 3
};

int vertices, edges;
int czas = 0;

const int BRAK = -1;

vector<vector<int> > graf;
vector<kolorek> kolor;
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
    if(TESTUJ)
        cerr << "READ INPUT DONE" << endl;
}

void graftest()
{
    for(int i=0;i<graf.size();i++)
    {
        cout << i <<  ": ";
        for(int j=0;j<graf[i].size();j++)
        {
            cout << graf[i][j] << " ";
        }
        cout << endl;
    }
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
    if(TESTUJ)
        cerr << "CLEAN DONE" << endl;
}

void test()
{
    for(int i=1;i<=vertices;i++)
        cout << parent[i] << " ";
    cout << endl;
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
    if(TESTUJ)
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
        if(parent[n]==-1)
        {
            lewy[n] = graf[n][0];
            visitVertex(graf[n][0]);
            parent[graf[n][0]] = n;
        }
        czas++;
        in[n] = czas;
    }
    else
    {
        if(graf[n].size()==2)
        {
            bool war = false;
            int i=0;
            if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
            {
                lewy[n]=graf[n][i];
                parent[graf[n][i]]=n;
                visitVertex(graf[n][i]);
                i++;
                czas++;
                in[n]=czas;

            }
            else
            {
                i++;
            }
            if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
            {
                if(graf[n][i-1]!=parent[n])
                {
                    parent[graf[n][i]]=n;
                    prawy[n]=graf[n][i];
                    visitVertex(graf[n][i]);
                }
                else
                {
                    parent[graf[n][i]]=n;
                    lewy[n]=graf[n][i];
                    visitVertex(graf[n][i]);
                    czas++;
                    in[n]=czas;
                }
            }
        }
        else if(graf[n].size()==3)
        {
            int i=0;
            bool war = false;
            if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
            {
                parent[graf[n][i]]=n;
                visitVertex(graf[n][i]);
                lewy[n]=graf[n][i];
                i++;
                war = true;
            }
            else
                i++;
            if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
            {
                if(war)
                {
                    parent[graf[n][i]]=n;
                    prawy[n]=graf[n][i];
                    czas++;
                    in[n]=czas;
                    visitVertex(graf[n][i]);
                    i++;
                }
                else
                {
                    parent[graf[n][i]]=n;
                    lewy[n]=graf[n][i];
                    war = true;
                    visitVertex(graf[n][i]);
                    i++;
                }
            }
            else
                i++;
            if(graf[n][i]!=parent[n] && kolor[graf[n][i]]==BIALY)
            {
                parent[graf[n][i]]=n;
                prawy[n]=graf[n][i];
                czas++;
                in[n]=czas;
                visitVertex(graf[n][i]);
            }
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
    if(TESTUJ)
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
    //if(TESTUJ)
      //  cerr << "GENERUJ DROGE DONE" << endl;
}

void readQuery()
{
    int query;
    cin >> query;
    for(int i=0;i<query;i++)
    {
        int z, cel;
        cin >> z >> cel;
        generujDroge(z,cel);
        cout << endl;
    }
    if(TESTUJ)
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
        //graftest();
        //test();
        readQuery();
        clean();
    }
}

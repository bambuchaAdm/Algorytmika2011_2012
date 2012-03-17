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

int vertices, edges;

vector<vector<int> > graf;
vector<int> kolor;
vector<int> pre;    //order
vector<int> in;
vector<int> post;

void readInput()
{
    cin >> vertices;
    edges = vertices - 1;
    const int MAX = vertices + 1;
    graf.resize(MAX);
    pre.resize(MAX);
    in.resize(MAX);
    post.resize(MAX);
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

int main()
{
    int z;
    cin >> z;
    for(int i=0;i<z;i++)
    {
        readInput();

        printOutput();
        //test();
        clean();
    }
}

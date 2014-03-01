#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int find(vector<int> &unionfind, int a);

struct Edge
{
    pair<int, int> edgeTo;
    int cost;
};

bool operator< (const Edge &leftnode, const Edge &rightnode)
{
    if (leftnode.cost != rightnode.cost) return leftnode.cost > rightnode.cost;
    if (leftnode.edgeTo.first != leftnode.edgeTo.first) return leftnode.edgeTo.first < rightnode.edgeTo.first;
    return false;
}

void addEdge(vector<int> &unionfind, int a, int b)
{
    int aRoot = find(unionfind, a);
    int bRoot = find(unionfind, b);
    unionfind[aRoot] = bRoot;
}

int find(vector<int> &unionfind, int a)
{
    if (unionfind[a] == a)
    {
        return a;
    }
    else
    {
        return find(unionfind, unionfind[a]);
    }
}

int main()
{
    ifstream fin("problem107.txt");

    priority_queue<Edge> edges;
    vector<int> unionfind;

    // INPUT

    for (int i = 0; i < 40; i++)
    {
        unionfind.push_back(i);
        string newline = "";
        getline(fin, newline);
        int a = 0;
        int count = 0;
        for (int j = 1; j < newline.size(); j++)
        {
            if (newline[j] == ',' && newline[j-1] != '-' && count < i )
            {
                int num = atoi(newline.substr(a, j - a).c_str());
                Edge edge;
                edge.cost = num;
                pair<int, int> p;
                p.first = i;
                p.second = count;
                edge.edgeTo = p;
                edges.push(edge);
                a = j+1;
            }
            if (newline[j] == ',')
            {
                count++;
            }
            if (newline[j-1] == '-')
            {
                a = j+1;
            }
        }
    }    
    int total = 0;
    while (!edges.empty())
    {
        Edge e = edges.top();
        edges.pop();
        if (find(unionfind, e.edgeTo.first) != find(unionfind, e.edgeTo.second))
        {
            addEdge(unionfind, e.edgeTo.first, e.edgeTo.second);
        }
        else
        {
            total += e.cost;
        }
    }
    cout << total << endl;
}

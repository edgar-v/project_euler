#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
    int x, y, cost, dist;

    Node(int _x, int _y, int _cost)
    {
        x = _x;
        y = _y;
        cost = _cost;
        dist = -1;
    }
};

struct CompareCost
{
    bool operator()(Node const& l, Node const& r)
    {
        return l.dist > r.dist;
    }
};

int main()
{
    ifstream fin("problem083.txt");
    vector<vector<Node> > nodes;
    string delim = ",";
    string line;
    while (getline(fin, line))
    {
        vector<Node> row;
        int pos = 0;
        int x = 0;
        while ((pos = line.find(delim)) != std::string::npos)
        {
            int cost = atoi(line.substr(0, pos).c_str());
            row.push_back(Node(x, nodes.size(), cost));
            line.erase(0, pos + delim.size());
            x++;
        }
        int cost = atoi(line.c_str());
        row.push_back(Node(x, nodes.size(), cost));
        nodes.push_back(row);
    }
    fin.close();
    
    int bestResult = -1;

    // Dijkstra
    for (int j = 0; j < nodes.size(); j++)
    {
        for (int k = 0; k < nodes.size(); k++)
        {
            nodes[j][k].dist = -1;
        }
    }
    std::priority_queue<Node, vector<Node>, CompareCost> pq;
    Node source = nodes[0][0];
    nodes[0][0].dist = source.cost;
    source.dist = source.cost;
    pq.push(source);
    while (!pq.empty())
    {
        Node u = pq.top();
        if (u.x == nodes.size() - 1 && u.y == nodes.size() - 1)
        {
            cout << u.dist << endl;
            break;
        }

        pq.pop();
        if (u.dist == -1)
            break;

        if (u.y > 0)
        {
            Node v = nodes[u.y - 1][u.x];
            if (v.dist == -1 || u.dist + v.cost < v.dist)
            {
                nodes[v.y][v.x].dist = u.dist + v.cost;
                v.dist = u.dist + v.cost;
                pq.push(v);
            }
        }

        if (u.y < nodes.size() - 1)
        {
            Node v = nodes[u.y + 1][u.x];
            if (v.dist == -1 || u.dist + v.cost < v.dist)
            {
                nodes[v.y][v.x].dist = u.dist + v.cost;
                v.dist = u.dist + v.cost;
                pq.push(v);
            }
        }

        if (u.x > 0)
        {
            Node v = nodes[u.y][u.x - 1];
            if (v.dist == -1 || u.dist + v.cost < v.dist)
            {
                nodes[v.y][v.x].dist = u.dist + v.cost;
                v.dist = u.dist + v.cost;
                pq.push(v);
            }
        }
        Node v = nodes[u.y][u.x + 1];
        if (v.dist == -1 || u.dist + v.cost < v.dist)
        {
            nodes[v.y][v.x].dist = u.dist + v.cost;
            v.dist = u.dist + v.cost;
            pq.push(v);
        }
    }

    return 0;
}

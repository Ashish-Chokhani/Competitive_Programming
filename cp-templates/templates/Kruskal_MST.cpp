#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    int findPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

public:
    void unionBySize(int u, int v)
    {
        int paru = findPar(u);
        int parv = findPar(v);
        if (paru == parv)
            return;
        else
        {
            if (size[paru] < size[parv])
            {
                parent[paru] = parv;
                size[parv] += size[paru];
            }
            else
            {
                parent[parv] = paru;
                size[paru] += size[parv];
            }
        }
    }

public:
    void unionByRank(int u, int v)
    {
        int paru = findPar(u);
        int parv = findPar(v);
        if (paru == parv)
            return;
        else
        {
            if (rank[paru] < rank[parv])
            {
                parent[paru] = parv;
            }
            else if (rank[paru] > rank[parv])
            {
                parent[parv] = paru;
            }
            else if (rank[paru] == rank[parv])
            {
                parent[parv] = paru;
                rank[paru]++;
            }
        }
    }
};

void Kruskal()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>>adj;
    vector<pair<int,pair<int,int>>>new_adj;
    DSU dsu(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj.push_back({wt,{u,v}});
    }
    sort(adj.begin(), adj.end());
    for(auto it:adj)
    {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(dsu.findPar(u)!=dsu.findPar(v))
            {

                dsu.unionByRank(u,v);
                new_adj.push_back({wt,{u,v}});
            }
    }
    for(auto it: new_adj)
    {
        cout<<it.second.first<< " "<<it.second.second<<" "<<it.first<<"\n";
    }
}

int main()
{
    Kruskal();
    return 0;
}
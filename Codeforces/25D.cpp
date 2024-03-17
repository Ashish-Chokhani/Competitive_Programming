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

void solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
    vector<pair<int, int>> oldRoads;
    vector<int>newRoads1;
    set<int> newRoads;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dsu.findPar(u) != dsu.findPar(v))
        {
            dsu.unionByRank(u, v);
        }
        else
        {
            oldRoads.push_back({u, v});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        newRoads.insert(dsu.findPar(i));
    }
    int size = newRoads.size();
    cout<<size-1<<"\n";
    int control=0;
    for(auto it=newRoads.begin();it!=newRoads.end();it++)
    {
    newRoads1.push_back(*it);
    }
    control=0;
    for (int i = 1; i < size; i++)
    {
    cout<<oldRoads[control].first<<" "<<oldRoads[control].second<<" "<<newRoads1[control]<<" "<<newRoads1[control+1];
    control++;
    cout<<"\n";
    }
}

int main()
{
    solve();
    return 0;
}
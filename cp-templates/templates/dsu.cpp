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
    bool isSameComponent(int u,int v)
    {
        return findPar(u)==findPar(v);
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
    cin>>n;
    DSU dsu(n);
    dsu.unionBySize(1,2);
    cout<<dsu.findPar(2)<<"\n";
    dsu.unionBySize(3,4);
    cout<<dsu.findPar(4)<<"\n";
    dsu.unionBySize(1,3);
    cout<<dsu.findPar(4)<<"\n";
}

int main()
{
    solve();
    return 0;
}

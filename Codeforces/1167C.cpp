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

    void printSize(int cur)
    {
        cout << size[cur] << " ";
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        int first = -1;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            if (first == -1)
            {
                first = x;
            }
            else
            {
                dsu.unionBySize(first, x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int par = dsu.findPar(i);
        dsu.printSize(par);
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}

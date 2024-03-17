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
    int n,m1,m2;
    cin>>n >> m1 >>m2;
    DSU dsu1(n),dsu2(n);
    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin>>u>>v;
        dsu1.unionByRank(u,v);
    }
    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin>>u>>v;
        dsu2.unionByRank(u,v);
    }
    vector<pair<int,int>>ans;
    for(int j=2;j<=n;j++)
    {
        if(!dsu1.isSameComponent(1,j) && !dsu2.isSameComponent(1,j))
        {
            ans.push_back({1,j});
            dsu1.unionByRank(1,j);
            dsu2.unionByRank(1,j);
        }
    }
    int l=1,r=1;
    while(l<=n && r<=n)
    {
        if(dsu1.isSameComponent(1,l))
        l++;
        else if(dsu2.isSameComponent(1,r))
        r++;
        else
        {
            ans.push_back({l,r});
            dsu1.unionByRank(1,l);
            dsu2.unionByRank(1,r);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it:ans)
    {
        cout<<it.first<<" "<<it.second<<"\n";
    }
}

int main()
{
    solve();
    return 0;
}

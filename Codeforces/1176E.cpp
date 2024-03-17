#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU
{
    vector<ll> parent, size, rank;

public:
    DSU(ll n)
    {
        for (ll i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    ll findPar(ll node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

public:
    void unionBySize(ll u, ll v)
    {
        ll paru = findPar(u);
        ll parv = findPar(v);
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
    void unionByRank(ll u, ll v)
    {
        ll paru = findPar(u);
        ll parv = findPar(v);
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

void DFS(ll cur,ll par,vector<ll>*g,bool isTake,vector<ll>&ans)
{
    //cout<<cur<<" "<<isTake<<"\n";
    if(isTake)
        ans.push_back(cur);
    for(auto it:g[cur])
    {
        if(it!=par)
        {
            DFS(it,cur,g,!isTake,ans);
        }
    }
}

void Kruskal()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,pair<ll,ll>>>adj;
    vector<pair<ll,pair<ll,ll>>>new_adj;
    DSU dsu(n);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, wt;
        cin >> u >> v;
        --u;
        --v;
        wt=1;
        adj.push_back({wt,{u,v}});
    }
    sort(adj.begin(), adj.end());
    for(auto it:adj)
    {
            ll u=it.second.first;
            ll v=it.second.second;
            ll wt=it.first;
            if(dsu.findPar(u)!=dsu.findPar(v))
            {

                dsu.unionByRank(u,v);
                new_adj.push_back({wt,{u,v}});
            }
    }
    vector<ll>g[n+1];
    for(auto it:new_adj)
    {
        ll u=it.second.first;
        ll v=it.second.second;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll>ans1,ans2;
    DFS(0,-1,g,false,ans1);
    DFS(0,-1,g,true,ans2);
    ll take=0;
    if(ans2.size()<ans1.size())
    {
        take=1;
    }
    if(take==0)
    {
    cout<<ans1.size()<<"\n";
    for(auto it:ans1)
    {
        cout<<it+1<<" ";
    }
    cout<<"\n";
    }
    else
    {
    cout<<ans2.size()<<"\n";
    for(auto it:ans2)
    {
        cout<<it+1<<" ";
    }
    cout<<"\n";
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    Kruskal();
    }
    return 0;
}
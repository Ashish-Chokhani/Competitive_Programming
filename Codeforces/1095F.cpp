#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>arr(200001,0);

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

void Kruskal()
{
    ll n, m;
    cin >> n >> m;
    ll mini_node=-1,mini_cost=1e16;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<mini_cost)
        {
            mini_cost=arr[i];
            mini_node=i;
        }
    }
    vector<pair<ll,pair<ll,ll>>>adj;
    vector<pair<ll,pair<ll,ll>>>new_adj;
    DSU dsu(n);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        --u;
        --v;
        adj.push_back({min(arr[u]+arr[v],wt),{u,v}});
    }
    for (ll i = 0; i < n; i++)
    {
        if(i!=mini_node)
        adj.push_back({arr[i]+arr[mini_node],{i,mini_node}});
    }
    sort(adj.begin(), adj.end());
    for(auto it:adj)
    {
            ll u=it.second.first;
            ll v=it.second.second;
            ll wt=it.first;
            if(dsu.findPar(u)!=dsu.findPar(v))
            {
                dsu.unionBySize(u,v);
                new_adj.push_back({wt,{u,v}});
            }
    }
    ll ans=0;
    for(auto it:new_adj)
    {
        ans+=it.first;
    }
    cout<<ans<<"\n";
}

int main()
{
    Kruskal();
    return 0;
}
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

vector<ll> dp(100001,0);
ll ans=0;

void DFS(ll cur,ll par,vector<pair<ll,ll>>*g,ll k,ll wt)
{
    for(auto it:g[cur])
    {
        if(it.first!=par)
        {
            DFS(it.first,cur,g,k,it.second);
            dp[cur]+=dp[it.first];
        }
    }
    if(min(dp[cur],k-dp[cur])>0)
    {
        ans=max(ans,wt);
    }
}

void Kruskal()
{
    ll n, m,k;
    cin >> n >> m >>k;
    vector<pair<ll,pair<ll,ll>>>adj;
    vector<pair<ll,pair<ll,ll>>>new_adj;
    vector<ll>x(k);
    for(ll i=0;i<k;i++)
    {
        cin>>x[i];
        --x[i];
        dp[x[i]]=1;
    }
    DSU dsu(n);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        --u;
        --v;
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
    vector<pair<ll,ll>>g[n];
    for(auto it:new_adj)
    {
        g[it.second.first].push_back(make_pair(it.second.second,it.first));
        g[it.second.second].push_back(make_pair(it.second.first,it.first));
    }
    DFS(0,-1,g,k,0);
    for(ll i=0;i<k;i++)
    {
        cout<<ans<<" ";
    }
}

int main()
{
    Kruskal();
    return 0;
}
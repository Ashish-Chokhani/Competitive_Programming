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
    bool isSameComponent(ll u,ll v)
    {
        return findPar(u)==findPar(v);
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

void solve()
{
    ll n,m;
    cin>>n>>m;
    DSU dsu(n);
    vector<ll>h(n);
    for(ll i=0;i<n;i++){
        cin>>h[i];
    }
    vector<pair<ll,pair<ll,ll>>>adj;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj.push_back({max(h[u],h[v]),{u,v}});
    }
    sort(adj.begin(),adj.end());
    ll q;
    cin>>q;
    vector<pair<ll,pair<ll,pair<ll,ll>>>>queries(q);
    for(ll i=0;i<q;i++){
        ll a,b,e;
        cin>>a>>b>>e;
        --a;
        --b;
        queries[i]={h[a]+e,{a,{b,i}}};
    }
    sort(queries.begin(),queries.end());
    ll i=0,j=0;
    vector<ll>ans(q,0);
    while(i<q){
        ll ind=queries[i].second.second.second;
        ll u=queries[i].second.first;
        ll v=queries[i].second.second.first;
        ll maxLimit=queries[i].first;
        while(1){
            if(j>=m) break;
            ll reqEnergy=adj[j].first;
            ll node1=adj[j].second.first;
            ll node2=adj[j].second.second;
            if(reqEnergy>maxLimit) break;
            j++;
            dsu.unionByRank(node1,node2);
        }
        if(dsu.isSameComponent(u,v)) ans[ind]=1;
        i++;
    }
    for(auto it:ans){
        if(it==0) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
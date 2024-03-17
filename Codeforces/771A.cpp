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
    ll findSize(ll cur)
    {
        return size[cur];
    }
};
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll>adj[n];
    DSU dsu(n);
    for (ll i = 1; i <= m; i++)
    {
       ll u,v;
       cin>>u>>v;
       --u;
       --v;
       dsu.unionBySize(u,v);
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    for (ll i = 0; i < n; i++)
    {
        ll par = dsu.findPar(i);
        if(adj[i].size()!=dsu.findSize(par)-1)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
 
int main()
{
    solve();
    return 0;
}
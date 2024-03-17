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
    ll n;
    cin>>n;
    DSU dsu(200001);
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll ans=0;
    for(ll i=0;i<n/2;i++)
    {
        if(!dsu.isSameComponent(arr[i],arr[n-1-i]))
        {
            ans++;
            dsu.unionByRank(arr[i],arr[n-1-i]);
        }
    }
    cout<<ans<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
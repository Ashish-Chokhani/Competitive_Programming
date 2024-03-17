#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,vector<ll>&vis,ll &cnt,vector<ll>*adj)
{
    vis[cur]=1;
    for(auto it:adj[cur])
    {
        if(!vis[it])
        {
            cnt++;
            DFS(it,vis,cnt,adj);
        }
    }
}

void solve()
{
    ll n,k;
    cin>>n >>k;
    vector<ll>adj[n+1];
    for(ll i=0;i<k;i++)
    {
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>vis(n,0);
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])

        DFS(i,vis,cnt,adj);
    }
    cout<<k-cnt<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,ll par,vector<ll>&vis,vector<ll>*adj)
{
    vis[cur]=1;
    for(auto it:adj[cur])
    {
        if(it!=par)
        DFS(it,cur,vis,adj);
    }
}

void solve()
{
    ll n,t;
    cin>>n>>t;
    vector<ll> adj[n+1];
    for(ll i=1;i<n;i++)
    {
        ll a;
        cin>>a;
        adj[i].push_back(i+a);
    }
    vector<ll>vis(n+1,0);
    DFS(1,-1,vis,adj);
    if(vis[t])
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,ll par,vector<ll>*adj,vector<ll>&dp)
{
    for(auto it:adj[cur])
    {
        if(it!=par)
        {
        DFS(it,cur,adj,dp);
        dp[cur]+=dp[it];
        }
    }
    dp[cur]=max(dp[cur],1LL);
}


void solve()
{
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>dp(n+1,0);
    DFS(0,-1,adj,dp);
    ll q;
    cin>>q;
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        cout<<dp[u]*dp[v]<<"\n";
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
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,ll par,vector<ll>*adj,vector<ll>&dp,vector<ll>&sz,vector<ll>&arr){
    sz[cur]=1;
    for(auto it:adj[cur]){
        if(it==par) continue;
        DFS(it,cur,adj,dp,sz,arr);
        sz[cur]+=sz[it];
    }
    for(auto it:adj[cur]){
        if(it==par) continue;
        dp[cur]+=sz[it]*(arr[cur]^arr[it]);
        dp[cur]+=dp[it];
    }
}

void DFS2(ll cur,ll par,ll n,vector<ll>*adj,vector<ll>&dp,vector<ll>&sz,vector<ll>&arr,vector<ll>&ans){
    if(cur==0){
        ans[cur]=dp[cur];
    }
    else{
        ll val=(arr[cur]^arr[par])*sz[cur];
        ans[cur]=ans[par]-val+(arr[cur]^arr[par])*(n-sz[cur]);
    }
    for(auto it:adj[cur]){
        if(it==par) continue;
        DFS2(it,cur,n,adj,dp,sz,arr,ans);
    }
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>dp(n+1,0),ans(n+1,0),sz(n+1,0);
    DFS(0,-1,adj,dp,sz,arr);
    DFS2(0,-1,n,adj,dp,sz,arr,ans);
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt=0;
    while (t--)
    {
        solve();
    }
    return 0;
}
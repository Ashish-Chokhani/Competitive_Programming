#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,ll par,vector<ll>*adj,vector<vector<ll>>&dp,vector<ll>&arr){
    dp[cur][0]=arr[cur];
    ll nchild=0;
    for(auto it:adj[cur]){
        if(it!=par){
            nchild++;
            DFS(it,cur,adj,dp,arr);
            dp[cur][0]+=dp[it][0];
            dp[cur][1]+=max(dp[it][0]-arr[it],dp[it][1]);
        }
    }
    if(nchild!=0) dp[cur][1]+=arr[cur];
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>adj[n];
    for(ll i=0;i<n;i++){
        ll u;
        cin>>u;
        --u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(2,0));
    DFS(0,-1,adj,dp,arr);
    cout<<max(dp[0][0]-arr[0],dp[0][1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

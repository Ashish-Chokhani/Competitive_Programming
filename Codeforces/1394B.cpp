#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool fun(ll u,ll i,ll par,vector<pair<ll,ll>>*adj,vector<vector<ll>>&vis,vector<vector<ll>>&vis1,vector<vector<ll>>&dp){
    ll sz=adj[u].size();
    vis[u][i]=1;
    vis1[u][i]=1;
    if(dp[u][i]!=-1) return dp[u][i];
    for(ll j=0;j<sz;j++){
        ll v=adj[i][j].first;
        if(!vis[v][j]){
            if(fun(v,j,u,adj,vis,vis1,dp))
            return dp[u][i]=true;
        }
        else if(vis1[v][j] && v!=par)
        return dp[u][i]=true;
    }
    vis1[u][i]=0;
    return dp[u][i]=false;
}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        --u;
        --v;
        adj[u].push_back({v,wt});
    }
    for(ll i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<vector<ll>>vis(n+1,vector<ll>(10,0));
    vector<vector<ll>>vis1(n+1,vector<ll>(10,0));
    vector<vector<ll>>dp(n+1,vector<ll>(10,-1));
    fun(0,0,-1,adj,vis,vis1,dp);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<k;j++){
            if(!vis[i][j]){
                fun(i,j,-1,adj,vis,vis1,dp);
            }
        }
    }
    ll ans=1;
    for(ll outdegree=0;outdegree<k;outdegree++){
        ll val=0;
        for(ll j=0;j<=outdegree;j++){
            ll flag=true;
            for(ll i=0;i<n;i++){
                if(adj[i].size()!=outdegree+1) continue;
                if(dp[i][j]!=1) flag=false;
            }
            if(flag){
                cout<<outdegree<<" "<<j<<"\n";
                val++;
            }
        }
        ans*=val;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

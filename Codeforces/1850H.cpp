#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,vector<pair<ll,ll>>*adj,vector<ll>&vis,vector<ll>&dist){
    vis[cur]=1;

    for(auto it:adj[cur]){
        if(!vis[it.first]){
            dist[it.first]=dist[cur]+it.second;
            DFS(it.first,adj,vis,dist);
        }
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    vector<pair<pair<ll,ll>,ll>>c(m);
    for(ll i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        --u;
        --v;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,-wt});
        c[i]={{u,v},wt};
    }
    vector<ll>vis(n+1,0),dist(n+1,0);
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            DFS(i,adj,vis,dist);
        }
    }
    for(ll i=0;i<m;i++){
        ll u=c[i].first.first;
        ll v=c[i].first.second;
        ll wt=c[i].second;
        if(dist[v]-dist[u]!=wt){
            cout<<"No\n";
            return;
        }
    }
    cout<<"YES\n";
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
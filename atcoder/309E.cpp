#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans=0;

void DFS(ll cur,ll par,ll longest,vector<ll>*adj,vector<ll>&ins,vector<ll>&depth){
    if(ins[cur]!=-1){
        longest=max(longest,depth[cur]+ins[cur]);
    }

    if(depth[cur]<=longest) ans++;

    for(auto it:adj[cur]){
        if(it!=par)
        DFS(it,cur,longest,adj,ins,depth);
    }
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n];
    vector<ll>depth(n,0);
    vector<ll>ins(n,-1);
    for(ll i=1;i<=n-1;i++){
        ll u;
        cin>>u;
        --u;
        adj[u].push_back(i);
        adj[i].push_back(u);
        depth[i]=1+depth[u];
    }
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        --x;
        ins[x]=max(ins[x],y);
    }
    DFS(0,-1,-1,adj,ins,depth);
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}
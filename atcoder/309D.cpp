#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maxiDepth(vector<ll>*adj,ll n1,ll n2,ll cur){
    vector<ll>vis(n1+n2,0);
    queue<pair<ll,ll>>q;
    q.push({cur,0});
    vis[cur]=1;
    ll maxi=0;
    while(!q.empty()){
        ll node=q.front().first;
        ll dis=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(vis[it]) continue;
            q.push({it,dis+1});
            vis[it]=1;
            maxi=max(maxi,dis+1);
        }
    }
    return maxi;
}

void solve() {
    ll n1,n2,m;
    cin>>n1>>n2>>m;
    vector<ll>adj[n1+n2];
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll d1=maxiDepth(adj,n1,n2,0);
    ll d2=maxiDepth(adj,n1,n2,n1+n2-1);
    cout<<d1+d2+1<<"\n";
}

int main()
{
    solve();
    return 0;
}
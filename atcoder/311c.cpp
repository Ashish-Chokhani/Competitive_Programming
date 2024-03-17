#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool detectCycle(ll cur,ll par,vector<ll> *adj, vector<ll> &vis, vector<ll> &vis2,vector<ll>&parent,ll &start,ll &end)
{
    parent[cur]=par;
    vis[cur] = 1;
    vis2[cur] = 1;
    for (auto it : adj[cur])
    {
        if (!vis[it])
        {
            if (detectCycle(it,cur,adj, vis, vis2,parent,start,end))
                return true;
        }
        else if (vis2[it])
        {
            if(start==-1) {
                start=cur;
                end=it;
            }
            return true;
        }
    }
    vis2[cur] = 0;
    return false;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    for(ll i=0;i<n;i++){
        ll v;
        cin>>v;
        --v;
        adj[i].push_back(v);
    }
    vector<ll>vis(n+1,0),vis2(n+1,0),parent(n+1,-1);
    ll start=-1,end=-1;
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            detectCycle(i,-1,adj,vis,vis2,parent,start,end);
        }
    }
    vector<ll>ans;
    while(start!=end){
        ans.push_back(start);
        start=parent[start];
    }
    ans.push_back(end);
    cout<<ans.size()<<"\n";
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it+1<<" ";
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur, ll par,vector<ll> *adj,vector<ll>&parent,vector<ll>&leaves)
{
    parent[cur]=par;
    ll nchild=0;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            nchild++;
            DFS(it, cur, adj ,parent,leaves);
        }
    }
    if(nchild==0) leaves.push_back(cur);
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>parent(n+1),leaves;
    vector<ll>adj[n+1];
    ll root=-1;
    for(ll i=0;i<n;i++){
        ll p;
        cin>>p;
        --p;
        if(p==i) root=i;
        else{
        adj[p].push_back(i);
        adj[i].push_back(p);
        }
    }
    DFS(root,-1,adj,parent,leaves);
    vector<vector<ll>>ans;
    vector<ll>vis(n+1,0);
    for(auto cur:leaves){
        vector<ll>vec;
        while(cur!=-1 && !vis[cur]){
            vis[cur]=1;
            vec.push_back(cur);
            cur=parent[cur];
        }
        ans.push_back(vec);
    }
    for(ll i=0;i<ans.size();i++){
        reverse(ans[i].begin(),ans[i].end());
    }
    cout<<ans.size()<<"\n";
    for(ll i=0;i<ans.size();i++){
        cout<<ans[i].size()<<"\n";
        for(auto it:ans[i]){
            cout<<it+1<<" ";
        }
        cout<<"\n";
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
    ll cnt = 0;
    while (t--)
    {
        solve();
    }
}
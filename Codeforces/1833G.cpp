#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Cut(ll u,ll p,vector<ll>*adj,vector<ll>&par,vector<ll>&depth,vector<ll>&ans,map<pair<ll,ll>,ll>&mp)
{ 
    par[u]=p;
    for(auto it:adj[u])
    {
        if(it!=p)
        {
            Cut(it,u,adj,par,depth,ans,mp);
            depth[u]+=depth[it];
        }
    }
    depth[u]++;
    if(depth[u]==3)
    {
        depth[u]=0;
       for(auto it:adj[u])
       {
        if(par[it]!=u)
        ans.push_back(mp[{u,par[u]}]);
       }
    }
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    vector<ll>par(n+1),depth(n+1);
    vector<ll>ans;
    map<pair<ll,ll>,ll>mp;
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        mp[{u,v}]=i+1;
        mp[{v,u}]=i+1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n%3!=0)
    {
        cout<<"-1\n";
        return;
    }
    Cut(0,-1,adj,par,depth,ans,mp);
    sort(ans.begin(),ans.end());
    unique(ans.begin(),ans.end());
    if(ans.size() != (n/3)-1)
    {
        cout<<"-1\n";
        return;
    }
    cout<<ans.size()<<"\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
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
    while (t--)
    {
        solve();
    }
    return 0;
}

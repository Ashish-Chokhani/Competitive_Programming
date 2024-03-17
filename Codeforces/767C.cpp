#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll node1=-1,node2=-1;

void initializeDP(ll cur,ll par,vector<ll>*adj,vector<ll>&dp,vector<ll>&weight,vector<ll>&parent)
{
    dp[cur]=weight[cur];
    parent[cur]=par;
    for(auto it:adj[cur])
    {
        if(it!=par)
        {
            initializeDP(it,cur,adj,dp,weight,parent);
            dp[cur]+=dp[it];
        }
    }
}

void Cut(ll u,ll v,vector<ll>*adj)
{
    auto it=lower_bound(adj[u].begin(),adj[u].end(),v);
    auto it1=lower_bound(adj[v].begin(),adj[v].end(),u);
    adj[u].erase(it);
    adj[v].erase(it1);
}

void DFS(ll cur,ll par,vector<ll>*adj,vector<ll>&dp,vector<ll>&parent,ll val,ll &isCut)
{
    for(auto it:adj[cur])
    {
        if(it!=par)
        {
            DFS(it,cur,adj,dp,parent,val,isCut);
        }
    }
    if(!isCut && dp[cur]==val)
    {
        isCut=1;
        if(node1==-1)
        node1=cur;
        else 
        node2=cur;
    }
}

void solve()
{
    ll n;
    cin>>n;
    ll root=-1;
    vector<ll>adj[n+1],temp[n+1];
    vector<ll>weight(n+1),dp(n+1,0),parent(n+1,0);
    ll s=0;
    for(ll i=0;i<n;i++)
    {
        ll u,w;
        cin>>u>>w;
        --u;
        if(u==-1)
        root=i;
        if(u!=-1)
        adj[u].push_back(i);
        adj[i].push_back(u);
        weight[i]=w;
        s+=w;
    }
    if(s%3!=0)
    {
        cout<<"-1\n";
        return;
    }
    for(ll i=0;i<n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    initializeDP(root,-1,adj,dp,weight,parent);
    ll isCut=0;
    DFS(root,-1,adj,dp,parent,s/3,isCut);
    if(node1==-1 || node1==root)
    {
        cout<<"-1\n";
        return;
    }
    Cut(node1,parent[node1],adj);
    initializeDP(root,-1,adj,dp,weight,parent);
    isCut=0;
    DFS(root,-1,adj,dp,parent,s/3,isCut);
    if(node2==-1 || node2==root)
    {
        cout<<"-1\n";
        return;
    }
    cout<<node1+1<<" "<<node2+1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

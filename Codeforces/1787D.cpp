#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isVisited = false;
ll sz = 0;
ll sz1 = 0;

void DFS(ll cur, ll par, vector<ll> *a, vector<ll>&dp,vector<ll>&vis,ll n)
{
    //cout<<cur<<"\n";
    vis[cur]=1;
    if (cur == 0)
        isVisited = true;
    sz++;
    for (auto it : a[cur])
    {
        if (!vis[it])
        {
            DFS(it, cur, a, dp,vis,n);
            dp[cur] += dp[it];
        }
    }
    dp[cur]++;
    if(cur!=n)
    {
    sz1 += n+dp[cur];
    }
}

void ZEROInitialize(vector<ll>&V)
{
    for(ll i=0;i<V.size();i++)
    {
        V[i]=0;
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    vector<ll> dp(n + 1, 0);
    vector<ll>vis(n+1,0);
    ll temp_sz=0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> adj[n + 1], rev[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        ll cur = i - 1 + arr[i];
        if (cur >= n || cur < 0)
            cur = n;
        adj[i - 1].push_back(cur);
        rev[cur].push_back(i - 1);
    }
    ZEROInitialize(vis);
    DFS(n, -1, rev, dp,vis,n);
    ll x=sz;
    x--;
    ll ans=0;
    sz=0;
    if (!isVisited)
    {
        ZEROInitialize(vis);
        DFS(0,0, adj, dp,vis,n);
        for(ll i=0;i<n;i++)
        {
            if(vis[i])
            ans+=x+n+1;
        }
        cout<<ans<<"\n";
        return;
    }
    sz = 0;
    sz1 = 0;
    for(ll i=0;i<=n;i++)
    {
        dp[i]=0;
    }    
    ZEROInitialize(vis);
    DFS(n,-1,rev, dp,vis,n);
    vector<ll>g(dp.begin(),dp.end());
    ZEROInitialize(vis);
    DFS(0,-1,adj, dp,vis,n);
    for(ll i=0;i<n;i++)
    {
        if(vis[i])
        ans+=x-g[i]+n+1;
        else
        ans+=2*n+1;
    }
    cout << ans << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        isVisited = false;
        sz = 0;
        sz1 = 0;
        solve();
    }
    return 0;
}

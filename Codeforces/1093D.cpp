#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long int MAXN = 1e5+1,p=998244353;
 
/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p)
{
    long long res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}


ll ans = 1;
queue<pair<pair<ll, ll>,ll>> q;

ll BFS(ll cur,vector<ll>&vis,vector<ll>*adj,vector<ll>&level)
{
    ll cnt=0,ans1=0,flag=0;
    q.push({{cur, 0},-1});
    while (!q.empty())
    {
        ll node = q.front().first.first;
        ll lev = q.front().first.second;
        level[node]=lev;
        ll par=q.front().second;
        q.pop();
        vis[node]=1;
        if(lev%2==0)
        cnt++;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it]=1;
                q.push({{it, lev + 1},node});
            }
            else if(vis[it] && level[it]==level[node])
            {
                flag=1;
            }
        }
    }
    if(!flag)
    ans1=(ans1%p+(exp(2LL,cnt,p))%p)%p;
    return ans1;
}

queue<pair<pair<ll, ll>,ll>> q1;

ll BFS2(ll cur,vector<ll>&vis1,vector<ll>*adj,vector<ll>&level1)
{
    ll cnt=0,ans2=0,flag=0;
    q1.push({{cur, 0},-1});
    while (!q1.empty())
    {
        ll node = q1.front().first.first;
        ll lev = q1.front().first.second;
        level1[node]=lev;
        ll par=q1.front().second;
        q1.pop();
        vis1[node]=1;
        if(lev%2==1)
        cnt++;
        for (auto it : adj[node])
        {
            if (!vis1[it])
            {
                vis1[it]=1;
                q1.push({{it, lev + 1},node});
            }
            else if(vis1[it] && level1[it]==level1[node])
            {
                flag=1;
            }
        }
    }

    if(!flag)
    ans2=(ans2%p+(exp(2LL,cnt,p))%p)%p;
    return ans2;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n];
    vector<ll> vis(n, 0),vis1(n,0);
    vector<ll> level(n, 0),level1(n,0);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
        ll z1=BFS(i,vis,adj,level)%p;
        ll z2=BFS2(i,vis1,adj,level1)%p;
        ans=(ans%p*(z1+z2)%p)%p;
        }
    }
    cout<<ans<<"\n";
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
        ans=1;
        solve();
    }
    return 0;
}

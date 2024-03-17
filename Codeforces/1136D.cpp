#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin >> n >>m;
    vector<ll>p(n);
    vector<ll>adj[n+1];
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
    }
    ll last=p[n-1];
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<ll>vis(n+1,0);
    ll need=1;
    vis[last]=1;
    ll ans=0;
    for(ll i=n-2;i>=0;i--)
    {
        ll has=0;
        for(auto it:adj[p[i]])
        {
            if(vis[it])
            has++;
        }
        if(has==need)
        ans++;
        else
        {
            need++;
            vis[p[i]]=1;
        }
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

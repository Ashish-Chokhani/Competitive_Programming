#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll vis[1001][1001];
vector<pair<ll,ll>>adj[1001][1002];

void DFS(ll x,ll y)
{
    vis[x][y]=1;
    for(auto it:adj[x][y])
    {
        if(!vis[it.first][it.second])
        DFS(it.first,it.second);
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i==j)
            continue;
            ll x=arr[i].first;
            ll y=arr[i].second;
            if(x==arr[j].first || y==arr[j].second)
            {
            adj[x][y].push_back({arr[j].first,arr[j].second});
            adj[arr[j].first][arr[j].second].push_back({x,y});
            }
        }
    }
    ll cnt=0;
    for(auto it:arr)
    {
        if(!vis[it.first][it.second])
        {
        DFS(it.first,it.second);
        cnt++;
        }
    }
    cout<<cnt-1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Djkistra(vector<pair<ll,ll>>*adj,ll n,vector<ll>&dist,vector<ll>&vis)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for(ll i=0;i<n;i++)
    {
        pq.push({dist[i],i});
    }
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();
        if(vis[node])
        {
            continue;
        }
        vis[node]=1;
        for (auto it : adj[node])
        {
            ll cur_dis = dist[it.first];
            if (dis + 2*it.second < cur_dis)
            {
                dist[it.first] = dis + 2*it.second;
                pq.push({dis + 2*it.second, it.first});
            }
        }
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<m;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        --u;
        --v;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<ll>dist(n+1);
    vector<ll>vis(n+1,0);
    for(ll i=0;i<n;i++)
    {
        cin>>dist[i];
    }
    Djkistra(adj,n,dist,vis);
    for(ll i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}
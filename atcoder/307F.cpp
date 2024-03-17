#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

vector<ll> Djkistra(vector<ll>&src,vector<pair<ll,ll>>*adj,ll n,ll k,ll D,vector<ll>&X)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, 1e12);
    vector<ll>days(n+1,-1);

    for(ll i=0;i<k;i++){
        dist[src[i]]=0;
        pq.push({0, src[i]});
        days[src[i]]=0;
    }
    
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            ll cur_dis = dist[it.first];
            if (dis + it.second < cur_dis)
            {
                dist[it.first] = dis + it.second;
                pq.push(make_pair(dis + it.second, it.first));
            }
        }
    }
    return days;
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        --u;
        --v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    ll k;
    cin>>k;
    vector<ll>src(k);
    for(ll i=0;i<k;i++){
        cin>>A[i];
        --A[i];
    }
    ll D;
    cin>>D;
    vector<ll>X(D);
    for(ll i=0;i<D;i++){
        cin>>X[i];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
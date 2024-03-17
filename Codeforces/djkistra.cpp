#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> Djkistra(ll src,vector<pair<ll,ll>>*adj,ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, 1e12);
    dist[src] = 0;
    pq.push(make_pair(0, src));
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
    return dist;
}
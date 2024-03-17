#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> arr(n), b(k);
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<pair<ll, ll>> adj[n+1];
  for (ll i = 0; i < m; i++)
  {
    ll u, v, wt;
    cin >> u >> v >> wt;
    --u;
    --v;
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
  }
  for (ll i = 0; i < k; i++)
  {
    cin >> b[i];
    --b[i];
  }
  for(ll i=0;i<n;i++)
  {
    adj[i].push_back(make_pair(n,arr[i]));
    adj[n].push_back(make_pair(i,arr[i]));
  }
  for (ll i = 0; i < k; i++)
  {
    ll src = b[i];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n+1,1e12);
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
    for (ll i=0;i<n;i++)
    {
      cout << dist[i] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
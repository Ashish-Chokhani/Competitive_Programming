#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<ll, ll>> bridges;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;--v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), tin(n + 1, -1), low(n + 1, -1), vis1(n + 1,0);
    ll timer = 1;
    function<void(int,int)>detectBridge=[&](int node,int parent)
	{
	    vis[node] = 1;
	    tin[node] = low[node] = timer++;
	    for (auto it : adj[node])
	    {
	    	if(it==parent) continue;
	        if (!vis[it])
	        {
	            detectBridge(it, node);
	            low[node] = min(low[node], low[it]);
	            if (low[it] > tin[node]) bridges.push_back({node,it});
	        }
	        else low[node] = min(low[node], tin[it]);
	    }
	};
    detectBridge(0, -1, adj, vis, tin, low, timer);
    for (auto it : bridges)
    {
        cout << it.first + 1 << " " << it.second + 1 << "\n";
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

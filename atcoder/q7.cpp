#include <bits/stdc++.h>
using namespace std;

vector<int> dp(100003, -1);

int DFS(int node, vector<int> &vis, vector<int> *adj)
{
    vis[node] = 1;
    if (dp[node] != -1)
        return dp[node];
    int maxi = 0;
    for (auto it : adj[node])
    {
        maxi = max(maxi, 1 + DFS(it, vis, adj));
    }
    return dp[node] = maxi;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            DFS(i, vis, adj);
    }
    int ans = 0;
    for (auto it : dp)
    {
        ans = max(ans, it);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
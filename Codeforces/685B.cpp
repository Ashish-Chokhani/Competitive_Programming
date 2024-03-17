#include <bits/stdc++.h>
using namespace std;

vector<int> Size(300001, 0), maxi_depth(300001, 0), centroid(300001, -1), parent(300000, -1);

int DFS(int cur, int par, vector<int> *adj)
{
    int nnodes = 0;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            nnodes += DFS(it, cur, adj);
        }
    }
    return Size[cur] = 1 + nnodes;
}

void DFS1(int cur, int par, vector<int> *adj, int n)
{
    int maxi_size = 0;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS1(it, cur, adj, n);
            maxi_depth[cur] = max(maxi_depth[cur], Size[it]);
        }
    }
}

void DFS2(int cur, int par, vector<int> *adj)
{
    for (auto it : adj[cur])
    {
        if (it != par)
            DFS2(it, cur, adj);
    }
    int req = Size[cur] / 2;
    if (maxi_depth[cur] <= req)
    {
        centroid[cur] = cur;
        return;
    }
    for (auto child : adj[cur])
    {
        if (Size[child] == maxi_depth[cur])
        {
            int targ = centroid[child];
            do
            {
                int above = Size[cur] - Size[targ];
                int below = maxi_depth[targ];
                if (max(above, below) <= req)
                    break;
                targ = parent[targ];
            } while (1);
            centroid[cur] = targ;
            break;
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        --u;
        adj[u].push_back(i);
        parent[i] = u;
    }
    DFS(0, -1, adj);
    DFS1(0, -1, adj, n);
    DFS2(0, -1, adj);
    while (q--)
    {
        int u;
        cin >> u;
        --u;
        cout << centroid[u] + 1 << "\n";
    }
}

int main()
{
    solve();
    return 0;
}
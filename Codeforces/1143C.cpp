#include <bits/stdc++.h>
using namespace std;

double DFS(int node, int par, vector<int> *adj)
{
    int nchild = 0;
    double sum = 0;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            double d = DFS(child, node, adj);
            sum += d;
            nchild++;
        }
    }
    if (nchild == 0)
        return 0;
    return 1.0 + (double)sum/nchild;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << setprecision(9) << DFS(0, -1, adj) << "\n";
}

int main()
{
    solve();
    return 0;
}

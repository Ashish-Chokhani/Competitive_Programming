#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(5002, vector<int>(5002, -1));
vector<vector<int>> par(5002, vector<int>(5002, -1));

int DFS(int src, int len, vector<pair<int, int>> *adj)
{
    if (len < 0)
        return 1e9 + 7;
    if (len == 0)
    {
        if (src == 0)
            return 0;
        return 1e9 + 7;
    }
    if (dp[src][len] != -1)
        return dp[src][len];

    int best = 1e9 + 6;
    for (auto it : adj[src])
    {
        int node = it.first;
        int cost = it.second + DFS(node, len - 1, adj);
        if (cost < best)
        {
            best = cost;
            par[src][len] = node;
        }
    }
    return dp[src][len] = best;
}

int main()
{
    int n, m, T;
    cin >> n >> m >> T;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        --u;
        --v;
        adj[v].push_back({u, wt});
    }
    int cur=0;
    for(int len=1;len<n;len++)
    {
        if(DFS(n-1,len,adj)<=T)
        cur=len;
    }
    cout<<cur+1<<"\n";
    int pos=n-1;
    vector<int>places;
    while(pos!=0)
    {
        places.push_back(pos);
        pos=par[pos][cur];
        cur--;
    }
    places.push_back(0);
    reverse(places.begin(),places.end());
    for(auto it:places)
    {
        cout<<it+1<<" ";
    }
    cout<<"\n";
}

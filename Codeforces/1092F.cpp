#include <bits/stdc++.h>
using namespace std;

vector<long long int> dp(200001, 0);
long long int ans = 0,start=0;

void DFS(long long int cur, long long int par, vector<long long int> *adj, vector<long long int> &arr)
{
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS(it, cur, adj, arr);
            dp[cur] += dp[it];
        }
    }
    dp[cur] += arr[cur];
}

void DFS2(long long int cur, long long int par, vector<long long int> *adj, vector<long long int> &arr,long long int depth)
{
    start+=(depth*arr[cur]);
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS2(it, cur, adj, arr,depth+1);
        }
    }
}

void DFS1(long long int cur, long long int par, vector<long long int> *adj,long long int last)
{
    ans = max(ans, last);
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS1(it, cur, adj,last + dp[0] - (2*dp[it]));
        }
    }
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long int> adj[n];
    for (long long int i = 1; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0, -1, adj, arr);
    DFS2(0, -1, adj, arr,0);
    DFS1(0, -1, adj,start);
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}
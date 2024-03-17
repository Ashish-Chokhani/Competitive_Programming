#include <bits/stdc++.h>
using namespace std;

vector<long long int> a(100000, 0);
long long int flag = 0;

void DFS(long long int src, long long int par, vector<long long int> *adj, vector<long long int> &s)
{
    long long int parSum = 0;
    if (par != -1)
        parSum = s[par];
    long long int mini = 1e9 + 5;
    for (auto child : adj[src])
    {
        mini = min(mini, s[child]);
        DFS(child, src, adj, s);
    }
    if (s[src] == -1)
    {
        if (adj[src].size() == 0)
            s[src] = parSum;
        else
            s[src] = mini;
    }
    if(s[src]==-1)
    flag=1;
}

long long int ans = 0;

void DFS1(long long int src, long long int prevSum, vector<long long int> *adj, vector<long long int> &s)
{
    long long int curSum = s[src];
    if (curSum < prevSum)
        flag = 1;
    ans += curSum - prevSum;
    for (auto child : adj[src])
    {
        DFS1(child, curSum, adj, s);
    }
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> adj[n];
    vector<long long int> s(n);
    for (long long int i = 1; i < n; i++)
    {
        long long int u;
        cin >> u;
        --u;
        adj[u].push_back(i);
    }
    for (long long int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    DFS(0, -1, adj, s);
    DFS1(0, 0, adj, s);
    if (flag)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
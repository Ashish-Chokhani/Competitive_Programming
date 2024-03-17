#include <bits/stdc++.h>
using namespace std;

const int k = 300;
//vector<int> V[100001];
vector<int> depth(100001,0);

// void flipArrays(vector<int> &arr1, vector<int> &arr2)
// {
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     if (n1 > n2)
//         return flipArrays(arr2, arr1);
// }

void AssignDepth(int cur, int par, vector<int> *adj, vector<int> &vis1)
{
    vis1[cur] = 1;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            AssignDepth(it, cur, adj, vis1);
            depth[cur] = max(depth[cur], 1 + depth[it]);
        }
    }
}

void DFS(int cur, int par, map<int, int> &type, int start, vector<int> *adj, vector<int> &vis, int &county)
{
    vis[cur] = 1;
    type[cur] = start;
    county++;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS(it, cur, type, start, adj, vis, county);
        }
    }
}

void DFS2(int cur, int par,int start, vector<int> *adj, vector<int> &vis3,vector<int>*V)
{
    vis3[cur] = 1;
    V[start].push_back(depth[cur]);
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS2(it, cur, start, adj, vis3,V);
        }
    }
}

double findExpectation(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int s = max(arr1[n1 - 1], arr2[n2 - 1]);
    vector<int> pre(n2, 0);
    pre[0] = arr2[0];
    double ans = 0;
    for (int i = 1; i < n2; i++)
    {
        pre[i] = arr2[i] + pre[i - 1];
    }

    for (int i = 0; i < n1; i++)
    {
        int index = lower_bound(arr2.begin(), arr2.end(), s - arr1[i]) - arr2.begin();
        ans += (index * s) + ((n2 - index) * (1 + arr1[i])) + pre[n2 - 1];
        if (index >= 1)
            ans -= (pre[index - 1]);
    }
    return (double)ans / (n1 * n2);
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> adj[n];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0), vis1(n, 0),vis3(n,0);
    map<int, int> type, sz;
    for (int i = 0; i < n; i++)
    {
        if (!vis1[i])
        {
            AssignDepth(i, -1, adj, vis1);
        }
    }
    //cout<<depth[0]<<" "<<depth[1]<<" "<<depth[2]<<"\n";
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int county = 0;
            DFS(i, -1, type, start, adj, vis, county);
            sz[start] = county;
            start++;
        }
    }
    vector<int> V[start];
    int counter=1;
    for (int i = 0; i < n; i++)
    {
        if (!vis3[i])
        {
            DFS2(i, -1,counter,adj, vis3,V);
            counter++;
        }
    }
    vector<pair<int, int>> types;
    for (int i = 1; i < start; i++)
    {
        types.push_back({sz[i], i});
    }
    sort(types.begin(), types.end());
    reverse(types.begin(), types.end());
    int l = types.size();
    int y = 0;
    map<pair<int, int>, double> ans;
    while (y < l && types[y].first > k)
    {
        for (int j = y + 1; j < l && types[j].first > k; j++)
        {
            vector<int> arr1 = V[types[y].second];
            vector<int> arr2 = V[types[j].second];
            double a = findExpectation(arr1, arr2);
            ans[{types[y].second, types[j].second}] = a;
            ans[{types[j].second, types[y].second}] = a;
        }
        y++;
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (type[u] == type[v])
        {
            cout << "-1\n";
            continue;
        }
        int sz1 = sz[type[u]];
        int sz2 = sz[type[v]];
        if (sz1 > k && sz2 > k)
        {
            cout << setprecision(12) << ans[{type[u], type[v]}] << "\n";
            continue;
        }
        vector<int> arr1 = V[type[u]];
        vector<int> arr2 = V[type[v]];
        cout << setprecision(12) << findExpectation(arr1, arr2) << "\n";
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
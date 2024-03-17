#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> isLeaf(100003, 0), dis(100003, 0);
bool isOdd = false;
ll maxi = 0;

void DFS(ll cur, ll par,vector<ll>*adj)
{
    ll nchild = 0;
    for (auto it : adj[cur])
    {
        nchild++;
        if (it != par)
            DFS(it, cur,adj);
    }
    if (nchild == 1)
        isLeaf[cur] = 1;
}

void DFS1(ll cur, ll par,vector<ll>*adj)
{
    if (par != -1)
        dis[cur] = dis[par] + 1;
    if (isLeaf[cur] && dis[cur] % 2 != 0)
        isOdd = true;
    for (auto it : adj[cur])
    {
        if (it != par)
            DFS1(it, cur,adj);
    }
}

void DFS2(ll cur, ll par,vector<ll>*adj)
{
    ll istrue = 0;
    for (auto it : adj[cur])
    {
        if (it != par && !isLeaf[it])
        {
            DFS2(it, cur,adj);
            maxi++;
        }
        else if (isLeaf[it])
            istrue = 1;
    }
    maxi+=istrue;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n+3];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0, -1,adj);
    ll root = -1;
    for (ll i = 0; i < n; i++)
    {
        if (isLeaf[i] == 1)
        {
            root = i;
            break;
        }
    }
    ll mini = 1;
    DFS1(root, -1,adj);
    if (isOdd)
        mini = 3;
    ll non_root = -1;
    for (ll i = 0; i < n; i++)
    {
        if (!isLeaf[i])
        {
            non_root = i;
            break;
        }
    }
    DFS2(non_root,-1,adj);
    cout<<mini<<" "<<maxi<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

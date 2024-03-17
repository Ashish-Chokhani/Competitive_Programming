#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool detectCycle(ll cur,vector<ll> *adj, vector<ll> &vis, vector<ll> &vis2)
{
    vis[cur] = 1;
    vis2[cur] = 1;
    for (auto it : adj[cur])
    {
        if (!vis[it])
        {
            if (detectCycle(it,adj, vis, vis2))
                return true;
        }
        else if (vis2[it])
            return true;
    }
    vis2[cur] = 0;
    return false;
}


void DFS(int node, vector<int> &vis, vector<int> *adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            DFS(it, vis, adj, st);
    }
    st.push(node);
}

void TopoSort(vector<int> &vis, vector<int> *adj, vector<int> &toposort,int n)
{
    stack<int> st;
    for(int node=1;node<=n;node++)
    {
        if(!vis[node])
        DFS(node, vis, adj, st);
    }
    while (!st.empty())
    {
        int node = st.top();
        toposort.push_back(node);
        st.pop();
    }
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n),cost(n);
    vector<ll>adj[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        --arr[i];
        adj[i].push_back(arr[i]);
    }
    for(ll i=0;i<n;i++){
        cin>>cost[i];
    }
    vector<ll>vis1(n,0),vis2(n,0);
    for(ll i=0;i<n;i++){
        if(!vis1[i]){
            vector<ll>cycles;
            findCycle(i,vis1,vis2,adj,cycles);

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
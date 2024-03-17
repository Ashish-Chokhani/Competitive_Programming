#include <bits/stdc++.h>
using namespace std;

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

void TopoSort(vector<int> &vis, vector<int> *adj, vector<int> &toposort, int n)
{
    stack<int> st;
    for (int node = 1; node <= n; node++)
    {
        if (!vis[node])
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
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin>>s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j-1] == 1)
                adj[i].push_back(j);
        }
    }
    vector<int> vis(n + 1, 0);
    vector<int> toposort;
    TopoSort(vis, adj, toposort, n);
    vector<int> arr(n + 1, 0);
    for (int i = 0; i < toposort.size(); i++)
    {
        arr[toposort[i]] = i + 1;
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==0)
        {
            cout<<"1 1";
        }
        else
        {
            cout<<arr[i]<<" ";
            for(int j=1;j<=arr[i];j++)
            {
                cout<<j<<" ";
            }
        }
        cout<<"\n";
    }   
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

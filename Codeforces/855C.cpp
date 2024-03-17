#include <bits/stdc++.h>
using namespace std;

int findAllWays(int src, int par, int type, int x, int n, int m, int k, vector<int> *trees)
{
    int ans=0,cnt=0;
    for(int child:trees[src])
    {
        if(child!=par)
        {
            if(type==0)
            {
                ans+=findAllWays(child,src,0,)
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> trees[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        trees[u].push_back(v);
        trees[v].push_back(u);
    }
    int k, x;
    cin >> k >> x;
}

int main()
{
    solve();
    return 0;
}

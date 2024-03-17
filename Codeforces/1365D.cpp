#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dr[] = {-1, 0, 0, 1};
ll dc[] = {0, 1, -1, 0};
ll cnt = 0;

void DFS(vector<string> &arr, vector<vector<ll>> &vis, ll row, ll col,ll n,ll m)
{
    vis[row][col] = 1;
    if(arr[row][col]=='G')
    cnt++;
    for (ll dir = 0; dir < 4; dir++)
    {
        ll nrow = row + dr[dir];
        ll ncol = col + dc[dir];
        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && arr[nrow][ncol] != '#' && !vis[nrow][ncol])
        {
            DFS(arr,vis,nrow,ncol,n,m);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    ll cnt_G = 0;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
        for(ll j=0;j<m;j++)
        {
            if(s[j]=='G')
            cnt_G++;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == 'B')
            {
                arr[i][j] = '#';
                for (ll dir = 0; dir < 4; dir++)
                {
                    ll nrow = i + dr[dir];
                    ll ncol = j + dc[dir];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && arr[nrow][ncol] != 'B')
                    {
                        arr[nrow][ncol] = '#';
                    }
                }
            }
        }
    }
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    if(arr[n-1][m-1]!='#')
    DFS(arr,vis,n-1,m-1,n,m);
    if(cnt==cnt_G)
    cout<<"Yes\n";
    else
    cout<<"No\n";
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
        cnt = 0;
        solve();
    }
}
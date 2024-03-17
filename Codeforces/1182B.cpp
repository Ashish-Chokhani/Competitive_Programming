#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }
    pair<int, int> centre = {-1, -1};
    int county = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i >= 1 && i < n - 1 && j >= 1 && j < m - 1 && !vis[i][j] && arr[i][j] == 1 && !vis[i - 1][j] && arr[i - 1][j] == 1 && !vis[i + 1][j] && arr[i + 1][j] == 1 && !vis[i][j - 1] && arr[i][j - 1] == 1 && !vis[i][j + 1] && arr[i][j + 1] == 1)
            {
                vis[i][j] = 1;
                county++;
                for (int y = i - 1; y >= 0 && arr[y][j] == 1; y--)
                {
                    vis[y][j] = 1;
                }
                for (int y = i + 1; y<n && arr[y][j] == 1; y++)
                {
                    vis[y][j] = 1;
                }
                for (int x = j - 1; x>=0 && arr[i][x] == 1;x--)
                {
                    vis[i][x] = 1;
                }
                for (int x = j + 1; x<m && arr[i][x] == 1;x++)
                {
                    vis[i][x] = 1;
                }
            }
        }
    }
    if(county!=1)
    {
        cout<<"NO\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && arr[i][j]==1)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

int main()
{
    solve();
    return 0;
}

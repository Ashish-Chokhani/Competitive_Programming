#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int county = 0, check = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '1')
                county++;
            else
            {
                check = max(check, 1);
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
                for (int dir = 0; dir < 8; dir++)
                {
                    int new_x = i + dx[dir];
                    int new_y = j + dy[dir];
                    if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0)
                    {
                        if (s[new_x][new_y] == '0')
                            check = 2;
                    }
                }
            }
        }
    }
    cout << county + check - 2 << "\n";
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
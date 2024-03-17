#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
    }
    set<int> rows, col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '*')
            {
                rows.insert(i);
                col.insert(j);
            }
        }
    }
    if (rows.size() > 1 && col.size() > 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

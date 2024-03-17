#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
        }
    }
    for (int col = 0; col < m; col++)
    {
        for (int row = n - 1; row >= 0; row--)
        {
            if (arr[row][col] == '*')
            {
                arr[row][col]='.';
                int j = row + 1;

                while (j < n && arr[j][col] == '.')
                    j++;

                j--;

                arr[j][col] = '*';

            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j];
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
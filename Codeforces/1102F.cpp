#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp(18, vector<vector<int>>(18, vector<int>(1 << 17, -1)));

int find_max_k(int first, int prev, int mask, vector<vector<int>> &matrix, vector<vector<int>> &cost1, vector<vector<int>> &cost2, int n)
{
    if (mask == ((1 << n) - 1))
        return cost2[first][prev];
    if (dp[first][prev][mask] != -1)
        return dp[first][prev][mask];
    int pick = 0;
    for (int bits = 0; bits < n; bits++)
    {
        if (!(mask & (1 << bits)))
        {
            pick = max(pick, min(cost1[bits][prev], find_max_k(first, bits, mask | (1 << bits), matrix, cost1, cost2, n)));
        }
    }
    return dp[first][prev][mask] = pick;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> cost1(n + 1, vector<int>(n + 1, 1e9 + 7));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < m; k++)
            {
                cost1[i][j] = min(cost1[i][j], abs(matrix[i][k] - matrix[j][k]));
            }
        }
    }
    vector<vector<int>> cost2(n + 1, vector<int>(n + 1, 1e9 + 7));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m - 1; k++)
            {
                cost2[i][j] = min(cost2[i][j], abs(matrix[i][k] - matrix[j][k + 1]));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, find_max_k(i, i, (1 << i), matrix, cost1, cost2, n));
    }
    cout << ans << "\n";
}

#include <bits/stdc++.h>
using namespace std;

long long int findMinimumCost(long long int curr_index, long long int left, long long int n, vector<long long int> &s, vector<long long int> &c, vector<vector<long long int>> &dp)
{
    // cout<<curr_index<<" "<<left<<"\n";
    if (left == 1)
        return c[curr_index];
    if (curr_index == 0)
        return 1e14;
    if (dp[curr_index][left] != -1)
        return dp[curr_index][left];
    long long int pick = 1e14, not_pick = 1e14;
    for (long long int index = curr_index - 1; index >= 0; index--)
    {
        if (s[index] < s[curr_index])
        {
            pick = min(pick, c[curr_index] + findMinimumCost(index, left - 1, n, s, c, dp));
        }
        if (curr_index == n - 1 || s[index] < s[curr_index])
        {
            not_pick = min(not_pick, findMinimumCost(index, left, n, s, c, dp));
        }
    }
    return dp[curr_index][left] = min(pick, not_pick);
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> s(n), c(n);
    vector<vector<long long int>> dp(n + 1, vector<long long int>(4, -1));
    for (long long int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (long long int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    long long int ans = findMinimumCost(n - 1, 3, n, s, c, dp);
    if (ans >= 1e12)
        ans = -1;
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}

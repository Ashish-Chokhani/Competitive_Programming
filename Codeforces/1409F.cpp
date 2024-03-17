#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp(202, vector<vector<int>>(202, vector<int>(202, -1)));

int findMaximum(int i, int count2, int k, string &s, int n, char c1, char c2)
{
    if (i < 0)
        return 0;
    if (dp[i][count2][k] != -1)
        return dp[i][count2][k];
    int replace1 = 0, replace2 = 0, not_replace2 = 0;
    if (s[i] != c1 && k > 0)
        replace1 = count2 + findMaximum(i - 1, count2 + (c1 == c2), k - 1, s, n, c1, c2);
    if (s[i] != c2 && k > 0)
        replace2 = findMaximum(i - 1, count2 + 1, k - 1, s, n, c1, c2);
    if (s[i] != c1)
        not_replace2 = findMaximum(i - 1, count2 + (s[i] == c2), k, s, n, c1, c2);
    else
        not_replace2 = count2 + findMaximum(i - 1, count2 + (s[i] == c2), k, s, n, c1, c2);
    return dp[i][count2][k] = max(replace1, max(replace2, not_replace2));
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string r;
    cin >> r;
    cout << findMaximum(n - 1, 0, k, s, n, r[0], r[1]) << "\n";
}

int main()
{
    solve();
    return 0;
}
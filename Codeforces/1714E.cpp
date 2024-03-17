#include <bits/stdc++.h>
using namespace std;

int check(int x, vector<int> &arr, vector<int> &dp, int n)
{
    dp[0] = 1;
    for (int index = 1; index <= n; index++)
    {
        if (arr[index] <= index - 1 && dp[index - arr[index] - 1])
            dp[index] = 1;

        if (n - index >= arr[index] && dp[index - 1])
            dp[index + arr[index]] = 1;
    }
    return dp[n];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> dp(n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    if (check(n, arr, dp, n))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
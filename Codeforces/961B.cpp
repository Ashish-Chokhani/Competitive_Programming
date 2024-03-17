#include <bits/stdc++.h>
using namespace std;

long long int Sum(vector<long long int> &sum, long long int l, long long int r)
{
    if (l >= 1)
        return sum[r] - sum[l - 1];

    return sum[r];
}

long long int MaximumSum(vector<long long int> &arr, vector<long long int> &t, long long int k,vector<long long int> &total)
{
    long long int n = arr.size();
    vector<vector<long long int>> dp(n, vector<long long int>(2, 0));
    for (long long int isUsed = 0; isUsed <= 1; isUsed++)
    {
        if (t[0] == 1 || ((!isUsed) && (k == 1)))
            dp[0][isUsed] = arr[0];
    }
    for (long long int index = 1; index < n; index++)
    {
        for (long long int isUsed = 0; isUsed <= 1; isUsed++)
        {
            long long int use = 0, not_use = 0;
            if (!isUsed && (index - k + 1) >= 0)
            {
                long long int sum = 0;
                sum = Sum(total, index - k + 1, index);
                if (index >= k)
                    use = sum + dp[index - k][1];
                else
                    use = sum;
            }
            if (t[index] == 0)
                not_use = dp[index - 1][isUsed];
            else
                not_use = arr[index] + dp[index - 1][isUsed];
            dp[index][isUsed] = max(use, not_use);
        }
    }
    return dp[n-1][0];
}

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n), t(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (long long int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    vector<long long int> sum(n, 0);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = arr[i] + sum[i - 1];
    }
    cout << MaximumSum(arr, t, k,sum) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

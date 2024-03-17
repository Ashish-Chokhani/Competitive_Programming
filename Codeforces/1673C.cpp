#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(long long int n)
{
    long long int rev = 0, temp = n;
    while (temp > 0)
    {
        long long int r = temp % 10;
        rev = rev * 10 + r;
        temp = temp / 10;
    }
    return rev == n;
}

void fun(long long int t, vector<long long int> &arr, vector<vector<long long int>> &dp)
{
    long long int n = arr.size();
    for (long long int target = 0; target <= t; target++)
    {
        dp[0][target] = (target % arr[0]) == 0;
    }
    for (long long int ind = 1; ind < n; ind++)
    {
        for (long long int target = 0; target <= t; target++)
        {
            long long int pick = 0;

            if (arr[ind] <= target)
                pick = dp[ind][target - arr[ind]];

            long long int not_pick = dp[ind - 1][target];
            dp[ind][target] = (pick + not_pick) % 1000000007;
        }
    }
}

void solve()
{
    vector<long long int> arr;
    for (long long int i = 1; i <= 4e4; i++)
    {
        if (isPalindrome(i))
            arr.push_back(i);
    }
    long long int l = arr.size();
    vector<vector<long long int>> dp(l, vector<long long int>(4e4+1, -1));
    fun(4e4, arr, dp);
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        cout << (dp[l - 1][n]) %1000000007 << "\n";
    }
}

int main()
{
    solve();
    return 0;
}
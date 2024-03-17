#include <bits/stdc++.h>
using namespace std;

long long int findSum(vector<long long int> &arr)
{
    long long int n = arr.size();
    vector<long long int> sum(n, 0);
    sum[n - 1] = arr[n - 1];
    for (long long int i = n - 2; i >= 0; i--)
    {
        sum[i] = arr[i] + sum[i + 1];
    }
    long long int ans = 0;
    for (long long int i = 0; i < n; i++)
    {
        ans += arr[i] * arr[i];
    }
    ans = ans * (n - 1);
    for (long long int i = 0; i < n - 1; i++)
    {
        ans += -2 * arr[i] * sum[i + 1];
    }
    return ans;
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr_x(n), arr_y(n);
    for (long long int i = 0; i < n; i++)
    {
        long long int x, y;
        cin >> x >> y;
        arr_x[i] = x;
        arr_y[i] = y;
    }
    cout << findSum(arr_x) + findSum(arr_y) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

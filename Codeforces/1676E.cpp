#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, q;
    cin >> n >> q;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    vector<long long int> sum(n);
    sum[0] = arr[0];
    for (long long int i = 1; i < n; i++)
    {
        sum[i] = arr[i] + sum[i - 1];
    }
    while (q--)
    {
        long long int val;
        cin >> val;
        long long int index = lower_bound(sum.begin(), sum.end(), val) - sum.begin();
        if (index == n)
        {
            cout << "-1\n";
        }
        else
        {
            cout << index + 1 << "\n";
        }
    }
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
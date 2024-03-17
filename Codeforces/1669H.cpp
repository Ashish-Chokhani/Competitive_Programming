#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> county(31, 0);
    for (int bits = 0; bits <= 30; bits++)
    {
        for (int i = 0; i < n; i++)
        {
            int no = arr[i];
            county[bits] += (no >> bits) & 1;
        }
    }
    for (int bits = 30; bits >= 0; bits--)
    {
        int required = n - county[bits];
        if (required <= k)
        {
            int mask = 1 << bits;
            for (int i = 0; i < n; i++)
            {
                int no = arr[i];
                int bit = (no >> bits) & 1;
                if (!bit)
                {
                    arr[i] = arr[i] | mask;
                    k--;
                }
            }
        }
    }
    int x = pow(2, 31) - 1;
    for (int i = 0; i < n; i++)
    {
        x = x & arr[i];
    }
    cout << x << "\n";
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
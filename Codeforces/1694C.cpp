#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    long long int last = n - 1, first = 0, flag = 1;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != 0)
            flag = 0;
        if (arr[i] != 0)
            last = i;
    }
    if (flag)
    {
        cout << "YES\n";
        return;
    }
    if (arr[last] > 0 || arr[first] < 0)
    {
        cout << "NO\n";
        return;
    }
    for (long long int i = 1; i <= last; i++)
    {
        arr[i]++;
    }
    vector<long long int> zero(last + 1, 0);
    for (long long int i = 0; i < last; i++)
    {
        if (zero[i] >= arr[i])
        {
            cout << "NO\n";
            return;
        }
        long long int x = zero[i] - arr[i] + 1;
        zero[i + 1] = x;
    }
    if (zero[last] != arr[last])
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
        return;
    }
}

int main()
{
    long long int t, n;
    cin >> t;
    while (t--)
    {
        solve();
    }
    //int count = 0;
    // while (t--)
    // {
    //     count++;
    //     if (count == 45)
    //     {
    //         cin >> n;
    //         vector<int> arr(n);
    //         for (int i = 0; i < n; i++)
    //         {
    //             cin >> arr[i];
    //         }
    //         cout << n << '.';
    //         for (int i = 0; i < n; i++)
    //         {
    //             cout << arr[i] << '.';
    //         }
    //     }
    //     solve();
    // }
    return 0;
}
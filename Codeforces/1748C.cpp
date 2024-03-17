#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    vector<long long int> sum(n, 0);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
            sum[i] = arr[i];
        else
            sum[i] = arr[i] + sum[i - 1];
    }
    long long int ans = 0, i;
    for (i = 0; (i < n) && (arr[i] != 0); i++)
    {
        if (sum[i] == 0)
            ans++;
    }
    long long int max_freq = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            map<long long int, long long int> mp;
            mp[sum[i]]++;
            max_freq = max(max_freq, mp[sum[i]]);
            i++;
            while (i < n && arr[i] != 0)
            {
                mp[sum[i]]++;
                max_freq = max(max_freq, mp[sum[i]]);
                i++;
            }
            ans += max_freq;
            max_freq = 0;
        }
        else
            i++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
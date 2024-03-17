#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long int k, long long int d, long long int c, long long int n, vector<long long int> &arr)
{
    long long int sum = 0, county = 0;
    while (county < d)
    {
        for (long long int i = n - 1; i >=(n - 1) - min(min(n - 1, k),d-county-1); i--)
        {
            sum+=arr[i];
        }
        county+=k+1;
    }
    return sum>=c;
}

void solve()
{
    long long int n, c, d, sum = 0;
    cin >> n >> c >> d;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (long long int i = n - 1; i >= n - min(n, d); i--)
    {
        sum += arr[i];
    }

    if (sum >= c)
    {
        cout << "Infinity\n";
        return;
    }

    if ((arr[n - 1] * d) < c)
    {
        cout << "Impossible\n";
        return;
    }

    long long int ans = 0;
    long long int low = 0, high = d;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        if (isPossible(mid, d, c, n, arr))
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
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
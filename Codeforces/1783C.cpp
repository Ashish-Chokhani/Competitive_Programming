#include <bits/stdc++.h>
using namespace std;

int findMaxWins(int m, int n, int exclude, vector<int> &arr, vector<pair<int, int>> &a)
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < n && sum + a[i].first <= m; i++)
    {
        if (a[i].second != exclude)
        {
            sum += a[i].first;
            cnt++;
        }
    }
    return cnt;
}

bool isPossible(int mid, int m, int n, vector<int> &arr, vector<pair<int, int>> &a)
{
    int point = n - mid;
    int required = point + 1;
    if (point < 0)
        return true;
    if (arr[point] <= m)
    {
        int win1 = findMaxWins(m - arr[point], n, point, arr, a)+1;
        if (win1 >= required-1)
            return true;
    }
    int win2 = findMaxWins(m, n, -1, arr, a);
    if (win2 >= required)
        return true;
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        a[i] = {arr[i], i};
    }
    sort(a.begin(), a.end());
    int l = 1, r = n + 1;
    int ans = n + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isPossible(mid, m, n, arr, a))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
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

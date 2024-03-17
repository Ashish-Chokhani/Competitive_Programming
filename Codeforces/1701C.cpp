#include <bits/stdc++.h>
using namespace std;

bool isPossibleToAssignTasks(vector<long long int> arr, long long int n, long long int m, long long int val)
{
    vector<long long int> time(n + 1, 0);
    for (long long int i = 0; i < m; i++)
    {
        time[arr[i]]++;
    }
    long long int county = 0, x = 0;
    for (long long int i = 1; i <= n; i++)
    {
        county += min(time[i], val);
        if (val > time[i])
            x += (val - time[i]) / 2;
    }
    long long int rem_tasks = m - county;
    return x >= rem_tasks;
}

long long int findMinimumTime(vector<long long int> arr, long long int n, long long int m)
{
    long long int low = 1;
    long long int high = m;
    long long int ans = 1e9 + 7;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        if (isPossibleToAssignTasks(arr, n, m, mid))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

void solve()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> arr(m);
    for (long long int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    cout << findMinimumTime(arr, n, m) << "\n";
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
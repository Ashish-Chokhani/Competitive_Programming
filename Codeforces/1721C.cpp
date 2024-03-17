#include <bits/stdc++.h>
using namespace std;

int findMinimum(int element, vector<int> &b, int n)
{
    int ans = 1e9 + 7;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid] - element < 0)
            l = mid + 1;
        else
        {
            ans = min(ans, b[mid] - element);
            r = mid - 1;
        }
    }
    return ans;
}

int findMaximum(int index, int element, vector<int> &a, vector<int> &b, int n,vector<int> & com)
{
    int ans = 0;
    int l = 0, r = n - 1,county=0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid] - element < 0)
            l = mid + 1;
        else if (abs(mid - index) > abs(com[mid] - com[index]))
        {
            r = mid - 1;
        }
        else
        {
            ans = max(ans, b[mid] - element);
            l = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int>com(n,0);
    int county=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= b[i - 1])
        {
            county++;
        }
        com[i] = county;
    }
    for (int i = 0; i < n; i++)
    {
        cout << findMinimum(a[i], b, n) << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << findMaximum(i, a[i], a, b, n,com) << " ";
    }
    cout << "\n";
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

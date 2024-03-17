#include <bits/stdc++.h>
using namespace std;

long long int findLeast(long long int n, long long int m)
{
    if (n < m)
        return n;
    while (n % m == 0 && n >= m)
    {
        n = n / m;
    }
    return n;
}

void solve()
{
    long long int n, m, k;
    cin >> n >> m;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    vector<long long int> b(k);
    for (long long int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    vector<pair<long long int, long long int>> a1,b1;
    for (long long int i = 0; i < n; i++)
    {
        long long int l1 = a1.size();
        long long int x = findLeast(a[i], m);
        if (l1 != 0 && a1[l1 - 1].first == x)
        {
            a1[l1 - 1].second += a[i] / x;
        }
        else
        {
            a1.push_back({x, a[i] / x});
        }
    }
    for (long long int i = 0; i < k; i++)
    {
        long long int l1 = b1.size();
        long long int x = findLeast(b[i], m);
        if (l1 != 0 && b1[l1 - 1].first == x)
        {
            b1[l1 - 1].second += b[i] / x;
        }
        else
        {
            b1.push_back({x, b[i] / x});
        }
    }
    if(a1.size()!=b1.size())
    {
        cout<<"No\n";
        return;
    }
    for (long long int i = 0; i < a1.size(); i++)
    {
        if(a1[i].first!=b1[i].first || a1[i].second!=b1[i].second)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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
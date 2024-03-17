#include <bits/stdc++.h>
using namespace std;

long long int FindNext(long long int i, long long int n)
{
    return i>0 ? i - 1 : n-1;
}

long long int maxi(long long int a, long long int b)
{
    return a > b ? a : b;
}

long long int minim(long long int a, long long int b)
{
    return a < b ? a : b;
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> a(n), b(n);
    for (long long int i = 0; i < n; i++)
    {
        long long int x, y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    vector<long long int> cost(n);
    long long int mini = 1e13,total=0;
    for (long long int i = 0; i < n; i++)
    {
        cost[i] = maxi(0,a[i]-b[FindNext(i,n)]);
        total+=cost[i];
    }
    long long int ans=LONG_LONG_MAX;
    for (long long int i = 0; i < n; i++)
    {
        ans=minim(ans,total-maxi(a[i]-b[FindNext(i,n)],0)+a[i]);
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
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> a(n), b(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (long long int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<long long int> c(a.begin(), a.end());
    sort(c.begin(), c.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++)
    {
        mp[c[i]] = b[i];
    }
    vector<long long int> prod(n);
    vector<long long int> d(n);
    long long int j = n;
    for (long long int i = 1; i <= n; i++)
    {
        d[i - 1] = j * i;
        j--;
    }
    for (long long int i = 1; i <= n; i++)
    {
        prod[i-1] = a[i-1] * d[i-1];
    }
    long long int s = 0;
    sort(prod.begin(),prod.end());
    for (long long int i = 0; i < n; i++)
    {
        s += ((prod[i]% 998244353) * (b[i]% 998244353)) % 998244353;
        s = s % 998244353;
    }
    cout << s << "\n";
}
int main()
{
    solve();
    return 0;
}

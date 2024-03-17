#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> p1(n+1,0);
    for (ll i = 0; i < n; i++)
    {
        p1[i+1] = p1[i] + (a[i] * b[i]);
    }
    ll ans = p1[n];
    for (ll c = 0; c < n; ++c)
    {
        ll cur = a[c] * b[c];
        for (ll l = c - 1, r = c + 1; l >= 0 && r < n; --l, ++r)
        {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + p1[l] + (p1[n] - p1[r + 1]));
        }
        cur = 0;
        for (ll l = c, r = c + 1; l >= 0 && r < n; --l, ++r)
        {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + p1[l] + (p1[n] - p1[r + 1]));
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(2 * n);
    ll ans1 = 0, ans2 = 1e16, ans3 = 1e16, ans4 = 1e16;
    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        ans1 += abs(arr[i]);
    }
    if (n == 1)
    {
        ans2 = abs(arr[0] - arr[1]);
    }
    else if (n == 2)
    {
        ll val = 0;
        for (ll i = 0; i < 4; i++)
        {
            val += abs(arr[i] - 2);
        }
        ans3 = min(ans3, val);
    }
    if (n % 2 == 0)
    {
        ll val = 0;
        for (ll i = 0; i < 2 * n; i++)
        {
            val += abs(arr[i] + 1);
        }
        for (ll i = 0; i < 2 * n; i++)
        {
            ll v=val-abs(arr[i] + 1);
            ans4=min(ans4,v+abs(arr[i]-n));
        }
    }
    cout<<min(ans1,min(ans2,min(ans3,ans4)))<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

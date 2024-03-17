#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll last_mini = 0, last_maxi = 0, ans = 1, l1 = 0, r1 = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll cur_mini = min(l, r);
        ll cur_maxi = max(l, r);
        if (cur_mini >= last_maxi)
        {
            ans = ans + cur_mini - last_maxi +1;
        if (l1==r1)
            ans--;
        }
        last_mini = cur_mini;
        last_maxi = cur_maxi;
        l1 = l;
        r1 = r;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

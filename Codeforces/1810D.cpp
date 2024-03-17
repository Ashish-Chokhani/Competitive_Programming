#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool overlap(ll l, ll r, ll cur_l, ll cur_r)
{
    if (l > cur_r || r < cur_l)
        return false;
    return true;
}

void solve()
{
    ll q;
    cin >> q;
    ll cnt=0;
    ll cur_l = -1e18 - 2, cur_r = 1e18 + 2;
    bool ok = false;
    while (q--)
    {
        cnt++;
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll a, b, n;
            cin >> a >> b >> n;
            ll l = ((n - 1) * (a - b)) + b + 1;
            if (n > 1)
                l = max(l, a + 1);
            else
                l = 1;
            ll r = ((n - 1) * (a - b)) + a;
            if (!overlap(l, r, cur_l, cur_r))
            {
                cout << "0 ";
            }
            else
            {
                cur_l = max(cur_l, l);
                cur_r = min(cur_r, r);
                cout << "1 ";
            }
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            ll val1 = max(1LL, (cur_r - b -1)/(a - b) + 1);
            ll val2 = max(1LL, (cur_l - b -1)/(a - b) + 1);
            if (val1 == val2)
                cout << val1 << " ";
            else
                cout << "-1 ";
        }
    }
    cout << "\n";
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

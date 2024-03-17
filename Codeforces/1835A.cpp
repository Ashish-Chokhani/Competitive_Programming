#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mini(ll digit)
{
    ll val = 1;
    for (ll i = 1; i < digit; i++)
    {
        val *= 10;
    }
    return val;
}

ll maxi(ll digit)
{
    ll val = 10;
    for (ll i = 1; i < digit; i++)
    {
        val *= 10;
    }
    return val - 1;
}

void solve()
{
    ll A, B, C, k;
    cin >> A >> B >> C >> k;
    if (C < min(A, B) || C > max(A, B) + 1)
    {
        cout << "-1\n";
        return;
    }
    ll min_C = max(mini(C), mini(A) + mini(B));
    ll min_A = max(mini(A), min_C - maxi(B));
    ll min_B = max(mini(B), min_C - maxi(A));
    ll max_C = min(maxi(C),maxi(A) + maxi(B));
    ll max_B = min(maxi(B), max_C - min_A);
    ll max_A = min(maxi(A), max_C - min_B);
    min_B = max(mini(B), min_C - min_A);
    ll cnt = max_B - min_B + 1;
    while (k - cnt > 0 && min_A < max_A && cnt > 0)
    {
        k -= cnt;
        min_A++;
        min_B = max(mini(B), min_C - min_A);
        max_B = min(maxi(B), max_C - min_A);
        cnt = max_B - min_B + 1;
    }
    if (k - cnt > 0)
    {
        cout << "-1\n";
        return;
    }
    min_C = max(mini(C), min_A + mini(B));
    min_B = max(mini(B), min_C - min_A + k - 1);
    ll val_c = min_B + min_A;
    if (val_c < min_C || val_c > max_C)
    {
        cout << "-1\n";
        return;
    }
    cout << min_A << " + " << min_B << " = " << val_c << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, cnt = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> xoR(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        cout << "XOR 1 " << i << endl;
        cin >> xoR[i];
    }
    bool isSame = false;
    ll ind = -1;
    for (ll i = 2; i <= n; i++)
    {
        if (xoR[i] == 0)
        {
            isSame = true;
            ind = i;
        }
    }
    if (isSame)
    {
        ll val;
        cout << "AND 1 " << ind << endl;
        cin >> val;
        cout << "! " << val << " ";
        for (ll i = 2; i <= n; i++)
        {
            cout <<(xoR[i]^val) << " ";
        }
        cout << endl;
        return;
    }
    map<ll, ll> mp;
    ll ind1 = -1, ind2 = -1;
    for (ll i = 2; i <= n; i++)
    {
        if (mp[xoR[i]])
        {
            ind1 = mp[xoR[i]];
            ind2 = i;
            ll val;
            cout << "AND " << ind1 << " " << ind2 << endl;
            cin >> val;
            ll a1 = xoR[ind1] ^ val;
            cout << "! " << a1 << " ";
            for (ll j = 2; j <= n; j++)
            {
                cout << (xoR[j] ^ a1) << " ";
            }
            cout << endl;
            return;
        }
        mp[xoR[i]] = i;
    }
    for (ll i = 2; i <= n; i++)
    {
        if (xoR[i] == n - 1)
        {
            ll ind = (i == n - 1) ? i - 1 : i + 1;
            ll y1, y2, y3, y4, y5, y6;
            y1=xoR[i];
            y2=xoR[ind]^y1;
            y3 = y1 ^ y2;
            y4=0;
            cout << "AND "<<i<<" "<<ind<< endl;
            cin >> y5;
            cout << "AND 1 "<<ind<< endl;
            cin >> y6;
            ll a2 = 0;
            for (ll bit = 0; bit < 16; bit++)
            {
                if (!((y1 >> bit) & 1))
                {
                    if ((y4 >> bit) & 1)
                        a2 = a2 | (1 << bit);
                }
                else
                {
                    if (!((y2 >> bit) & 1))
                    {
                        if ((y5 >> bit) & 1)
                            a2 = a2 | (1 << bit);
                    }
                    else if (!((y6 >> bit) & 1))
                    {
                        a2 = a2 | (1 << bit);
                    }
                }
            }
            ll a1=y1^a2;
            cout << "! " << a1 << " ";
            for (ll j = 2; j <= n; j++)
            {
                cout << (xoR[j] ^ a1) << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
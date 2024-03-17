#include "bits/stdc++.h"
#ifdef mlocal
#include "./Competitive-Code-Library/snippets/prettyprint.h"
#endif
using namespace std;
#define for_(i, s, e) for (int i = s; i < (int) e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> ii;
#define endl '\n'


ll rt(ll k) {
    ll ans = sqrtl(k);
    if (ans * ans == k) return ans;
    return -1;
}

int main() {
#ifdef mlocal
    freopen("test.in", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<ll, ll> freq;
        for_(i, 0, n) {
            ll k; cin >> k;
            freq[k]++;
        }

        int q; cin >> q;
        while (q--) {
            ll x, y; cin >> x >> y;
            ll det = rt(x * x - 4 * y);
            if (det == -1 or (x + det) % 2) {
                cout << 0 << " ";
                continue;
            }

            ll a = (x + det) / 2, b = (x - det) / 2;
            if (a == b and freq.count(a)) cout << (freq[a] * (freq[a] - 1)) / 2;
            else if (freq.count(a) and freq.count(b)) cout << freq[a] * freq[b];
            else cout << 0;

            cout << " ";
        }
        cout << endl;
    }
}


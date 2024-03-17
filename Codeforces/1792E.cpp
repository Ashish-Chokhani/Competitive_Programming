#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll n, m1, m2;
	cin >> n >> m1 >> m2;
	set<ll> primes;
	vector<vector<ll>> its_divisors;
	for (ll m : {m1, m2}) {
		vector<ll> v;
		for (ll d = 1; d * d <= m; d++) {
			if (m % d == 0) {
				v.push_back(d);
				if (d * d != m) {
					v.push_back(m / d);
				}
			}
		}
		for (ll d = 2; d * d <= m; d++) {
			if (m % d == 0) {
				primes.insert(d);
				while (m % d == 0) {
					m /= d;
				}
			}
			if (m != 1) {
				primes.insert(m);
			}
		}
		its_divisors.push_back(v);
	}
	set<ll> divisors;
	for (ll d1 : its_divisors[0]) {
		for (ll d2 : its_divisors[1]) {
			divisors.insert((ll) d1 * d2);
		}
	}
	
	unordered_map<ll,ll> dp;
	
	ll total_xor = 0;
	ll positive = 0;
	
	for (ll d : divisors) {
		// d = 30 -> 15, 10, 6
		ll& me = dp[d];
		if (d <= n) {
			me = d;
		}
		for (ll p : primes) {
			if (d % p == 0) {
				me = max(me, dp[d/p]);
			}
		}
		ll ans = d / me;
		if (ans > n) ans = 0;
		else positive++;
		total_xor ^= ans;
		// cout << ans << " ";
	}
	cout << positive << " " << total_xor << "\n";
	// cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
        solve();
    }
}
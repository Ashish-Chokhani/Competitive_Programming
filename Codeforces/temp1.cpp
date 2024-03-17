#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e18;

void Solve() 
{
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	vector<pair<int, int> > prefix_maximums;
	int prefix = 0, sum = 0;
	prefix_maximums.push_back({0, 0});
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		prefix += a[i];
		if(prefix > prefix_maximums.back().first)
		{
			prefix_maximums.push_back({prefix, i});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int tot = (b[i] - prefix_maximums.back().first);
		// cout << "tot = " << tot << "\n";
		int ans = 0;
		if(tot >= 0)
		{
			if(sum <= 0)
			{
				cout << "-1\n";
				continue;
			}
			ans = n * ((tot + sum - 1) / sum);
		}
		else
		{
			tot = b[i];
		}
		tot %= sum;
		if(tot == 0) tot = sum;
		int l = 0, r = prefix_maximums.size() - 1, midd = r;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(prefix_maximums[mid].first >= tot)
			{
				midd = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans += prefix_maximums[midd].second;
		cout << ans << "\n";
	}
}

int32_t main() 
{
	auto begin = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++) 
	{
		//cout << "Case #" << i << ": ";
		Solve();
	}
	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
	return 0;
}
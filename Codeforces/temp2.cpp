#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e18;

void Solve() 
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int dp[2][128]; // alternating rows, current xor. dp[i][j] = minimum of all last values possible
	for(int i = 0; i <= 1; i++)
	{
		for(int j = 0; j < 128; j++)
		{
			dp[i][j] = 1e9;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int cur = i % 2, prev = (i - 1) % 2;
        dp[cur][0] = 0;
		int bits_set = __builtin_popcountll(a[i]);
		for(int j = 0; j < 128; j++)
		{
			if(dp[prev][j] < a[i] && __builtin_popcountll(j) <= bits_set)
			{
				dp[cur][j ^ a[i]] = min(dp[cur][j ^ a[i]], a[i]);
				// if(dp[cur][j ^ a[i]] == -1)
				// {
				// 	dp[cur][j ^ a[i]] = a[i];
				// }
			}
		}
		// cout << "i = " << i << "\n";
		for(int j = 0; j < 128; j++)
		{
			// cout << dp[cur][j] << " ";
			dp[prev][j] = dp[cur][j];
		}
		// cout << "\n";
	}
	int ans = 0;
	for(int i = 0; i < 128; i++)
	{
		if(dp[n % 2][i] != 1e9) ans++;
	}
	cout << ans << "\n";
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
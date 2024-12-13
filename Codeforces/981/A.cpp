#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void dfs(vector<ll>& visited, vector<vector<ll>>& edges, ll node, ll& x)
{
    visited[node] = 1;
    x += 1;

    for(ll i = 0 ; i < edges[node].size(); i++)
    {
        if(visited[edges[node][i]])
            continue;
        dfs(visited, edges, edges[node][i], x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin >> t;
    while (t--)
    {
        ll n = 0, val = 0;
        ll MOD = 1000000007LL;
        // cin >> n >> k;
        for (ll k=1; k<=100000; k++) {
	        ll s = 2LL;
	        ll sum = 2LL;
	        ll x= 1LL;
	        ll y = 1LL;
	        if(k == 1LL)
	        {
	            cout << n % MOD << '\n';
	            continue;
	        }
	        while(true)
	        {
	            ll z = (x % k+ y % k) % k;
	            s = s + 1LL;
	            if(z % k == 0LL)
	            {
	                break;
	            }
	            ll temp;
	            temp = y;
	            y = z;
	            x = temp;
	        }
	        if (s >= val) {
	        	val = s;
	        	n = k;
	        }
    	}
    	cout << val << 'n << '/n';
        // cout << s << '/n';
        // cout << ((s % MOD)* (n % MOD) % MOD) << '\n';
        
    }
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(val);

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>>dp(n+1,vector<ll>(m+1,INF));
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=m;j++){
			if(i==j) dp[i][j]=0;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(i==j) continue;
			for(ll k=1;k<i;k++){
				dp[i][j]=min(dp[i][j],1LL+dp[i-k][j]+dp[k][j]);
			}
			for(ll k=1;k<j;k++){
				dp[i][j]=min(dp[i][j],1LL+dp[i][j-k]+dp[i][k]);
			}
		}
	}
	cout<<dp[n][m]<<"\n";
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    //#endif
    
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
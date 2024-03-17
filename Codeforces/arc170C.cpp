#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 998244353;
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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>s(n);
  for(ll &x:s){
  	cin>>x;
  }
	vector<ll>dp(n+1,0),temp(n+1,0);
	dp[0]=1;
	for(ll i=0;i<n;i++){
		fill(temp.begin(),temp.end(),0);
		for(ll j=0;j<=i;j++){
			if(s[i]==1){
				if(j<=m) temp[j+1]+=dp[j];
				temp[j+1]%=mod;
			}
			if(s[i]==0){
				temp[j]+=(j*dp[j])%mod;
				temp[j]%=mod;
				if(j<=m) temp[j+1]+=((m-j)*dp[j])%mod;
				temp[j+1]%=mod;
			}
		}
		dp=temp;
	}
	ll ans=0;
	for(ll j=0;j<=n;j++){
		ans+=dp[j];
		ans%=mod;
	}
	cout<<ans<<endl;
  }
  // Think about the case when N>M
  // If s[i]=='1' I have to fill that position with MEX 
  // Hence make sure MEX always exists for such i's
  // Mex doesn't exist when all numbers from 0 to M has been filled which requires at least (M+1) indices
  // There is a chance that MEX doesn't exist when N>(M+1) i.e M<N-1
  // Will non-Mex always exist?
  // If s[i]=='0' I have to fill that position with non-mex till index i-1

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
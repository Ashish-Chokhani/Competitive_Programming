#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
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

vector<ll> findPossible(ll last,ll m){
	vector<ll>arr;
	arr.push_back(last);
	if(last+1<=m) arr.push_back(last+1);
	if(last-1>=2) arr.push_back(last-1);
	return arr;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  ++m;
  vector<ll>arr(n);
  for(ll i=0;i<n;i++){
  	cin>>arr[i];
  	++arr[i];
  }
  vector<vector<ll>>dp(n+1,vector<ll>(m+2,0));
  for(ll last=0;last<=m;last++){
  	dp[0][last]=1;
  }
  for(ll i=1;i<=n;i++){
  	for(ll last=m;last>=0;last--){
  		ll val=0;
		vector<ll>possibleValues=findPossible(last,m);
		if(arr[i-1]!=1){
			ll flag=0;
			for(auto &num:possibleValues){
				if(arr[i-1]==num) flag=1;
			}
			if(flag) val=dp[i-1][arr[i-1]];
			val%=mod;
		}
		else{
			for(auto &num:possibleValues){
				val+=dp[i-1][num];
				val%=mod;
			}
		}
		dp[i][last]=val;
  	}
  }
  ll ans=0;
  if(arr[n-1]!=1) ans+=dp[n-1][arr[n-1]];
  else{
  	for(ll i=2;i<=m;i++){
  		ans+=dp[n-1][i];
  	}
  }
  cout<<dp[1][10]<<"\n";
  cout<<ans<<"\n";
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
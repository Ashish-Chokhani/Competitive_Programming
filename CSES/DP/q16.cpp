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

bool isPossible(ll rounds,ll mask,ll k,vector<ll>&arr){
	ll tot_wt=0,n=arr.size();
	for(ll i=0;i<n;i++){
		if(!(mask&1)) tot_wt+=arr[i];
		mask>>=1;
	}
	return (rounds*k)>=tot_wt;
}

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  sort(arr.begin(),arr.end());
  vector<vector<ll>>dp(n+1,vector<ll>(1LL<<n,INF));
  for(ll rounds=0;rounds<=n;rounds++){
  	dp[rounds][(1LL<<n)-1]=0;
  }
  for(ll rounds=1;rounds<=n;rounds++){
  	for(ll mask=0;mask<(1LL<<n);mask++){
  		if(isPossible(rounds,mask,k, arr)) 
  	}
  }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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

bool isAvailableToPick(ll num,ll i){
	return (num&(1LL<<i))!=0;
}

//dp[w] minimum number of rides required
//with the subset of people represented by w

void solve(){
  ll n,x;
  cin>>n>>x;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  vector<pair<ll,ll>>dp(1LL<<n,{INF,INF});
  dp[0]={1,0};
  for(ll mask=1;mask<(1LL<<n);mask++){
  	for(ll i=1;i<=n;i++){
  		if(!isAvailableToPick(mask,i-1)) continue;
  		ll new_weight=arr[i-1];
      ll space_taken=dp[mask^(1LL<<(i-1))].second;
  		if(new_weight+space_taken<=x){
  			dp[mask]=min(dp[mask],{dp[mask^(1LL<<(i-1))].first,new_weight+space_taken});
  		}
  		else{
  			dp[mask]=min(dp[mask],{dp[mask^(1LL<<(i-1))].first+1,new_weight});
  		}
  	}
  }
  cout<<dp[(1LL<<n)-1].first<<"\n";
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
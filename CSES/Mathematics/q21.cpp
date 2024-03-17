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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

const ll maxN=101;
vector<vector<double>>dp(maxN,vector<double>(6*maxN,0.0));
const double val=(double)1/6;

void solve(){
  ll n,a,b;
  cin>>n>>a>>b;
  for(ll i=1;i<=6;i++){
  	dp[1][i]=val;
  }
  for(ll trials=2;trials<=100;trials++){
	 for(ll alpha=1;alpha<=600;alpha++){
	    for(ll i=1;i<=6;i++){
	  		if(alpha>=i) dp[trials][alpha]+=val*dp[trials-1][alpha-i];
	  	}	
	}
  }
  double ans=0.0;
  for(ll i=a;i<=b;i++) ans+=dp[n][i];
  cout<<fixed<<setprecision(6)<<ans<<endl;
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
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


vector<vector<ll>>dp(1e6+2,vector<ll>(2,0));
// 0 represents width 2 block
void solve(){
  dp[1][0]=dp[1][1]=1;
  for(ll i=2;i<=1e6;i++){
  	ll op1=(dp[i-1][0]+dp[i-1][1])%mod;  //do not extend further(width 2)
  	ll op2=dp[i-1][1]%mod;     // extend both towers of width 1
  	ll op3=2*dp[i-1][1]%mod;  //extend either one of tower(width 1)
  	ll op4=dp[i-1][0]%mod;    //extend both towers of width 2
  	dp[i][0]+=(op4+op1)%mod;
  	dp[i][1]+=((op1+op2)%mod+op3)%mod;
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
    solve();
    while (t--)
    {
    	ll n;
    	cin>>n;
    	cout<<(dp[n][0]+dp[n][1])%mod<<"\n";
    }
    return 0;
}
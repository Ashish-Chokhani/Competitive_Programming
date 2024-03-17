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

void solve(){
  vector<vector<ll>>grid(8,vector<ll>(8,0));
  for(ll i=1;i<=7;i++){
  	string s;
  	cin>>s;
  	for(ll j=1;j<=7;j++) grid[i][j]=s[j-1]=='B';
  } 
  vector<ll>akt(2,0);
  vector<vector<ll>>mask(8,vector<ll>(8,0));
  for(ll i=2;i<=6;i++){
  	for(ll j=2;j<=6;j++){
  		ll bit=(i+j)&1;
  		if(grid[i-1][j-1] && grid[i+1][j-1] && grid[i-1][j+1] && grid[i+1][j+1] && grid[i][j]){
  			mask[i-1][j-1] |= (1LL<<akt[bit]);
  			mask[i-1][j+1] |= (1LL<<akt[bit]);
  			mask[i+1][j-1] |= (1LL<<akt[bit]);
  			mask[i+1][j+1] |= (1LL<<akt[bit]);
  			mask[i][j] |= (1LL<<akt[bit]);
  			akt[bit]++;
  		}
  	}
  }
  vector<vector<ll>>dp(2);
  dp[0]=vector<ll>((1LL<<akt[0]),INF);
  dp[0][0]=0;
  dp[1]=vector<ll>((1LL<<akt[1]),INF);
  dp[1][0]=0;
  for(ll i=1;i<=7;i++){
  	for(ll j=1;j<=7;j++){
  		ll bit=(i+j)&1;
  		for(ll k=(1LL<<akt[bit])-1;k>=0;k--){
  			dp[bit][k | mask[i][j]] = min(dp[bit][k | mask[i][j]],dp[bit][k]+1);
  		}
  	}
  }
  cout<<dp[0][(1LL<<akt[0])-1]+dp[1][(1LL<<akt[1])-1]<<endl;
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
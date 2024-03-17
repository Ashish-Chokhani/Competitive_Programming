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

#define F0R(i, a) for (int i=0; i<(a); i++)
void solve(){
  ll n,k;
  cin>>n>>k;
  ll dp[n+1][k+1]; 
  for(ll i=0;i<=n;i++){
  	for(ll j=0;j<=k;j++){
  		dp[i][j]=0;
  	}
  }
  //Dont forget to add base case and take mod
  for(ll i=0;i<k;i++) dp[0][i]=1;
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<k;j++){
  		for(ll z=0;z<k-j;z++){
  			if(i+((j+1)*(z+1))>n) break;
  			dp[i+(j+1)*(z+1)][z]+=dp[i][j];
  			dp[i+(j+1)*(z+1)][z]%=mod;
  		}
  	}
  }
  ll ans=0;
  for(ll i=0;i<k;i++){
  	ans+=dp[n][i];
  	ans%=mod;
  }
  cout<<ans<<endl;
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
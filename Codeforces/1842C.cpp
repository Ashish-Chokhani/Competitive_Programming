#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF=1000000000;
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
  ll n;
  cin>>n;
  vector<ll>arr(n+1);
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  vector<ll>dp(n+1,-INF),mx(n+1,-INF);
  dp[1]=0;
  mx[arr[1]]=-1;
  for(ll i=2;i<=n;i++){
  	dp[i]=max(dp[i],dp[i-1]);
  	dp[i]=max(dp[i],mx[arr[i]]+i+1);
  	mx[arr[i]]=max(mx[arr[i]],dp[i-1]-i);
  }
  cout<<dp[n]<<endl;
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
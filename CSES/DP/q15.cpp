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
  ll n;
  cin>>n;
  vector<pair<ll,pair<ll,ll>>>arr(n);
  for(ll i=0;i<n;i++){
  	cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
  }
  sort(arr.begin(),arr.end(),[](pair<ll,pair<ll,ll>>&i1,pair<ll,pair<ll,ll>>&i2){
  	return i1.second.first<i2.second.first;
  });
  vector<ll>temp(n);
  for(ll i=0;i<n;i++){
  	temp[i]=arr[i].second.first;
  }
  vector<ll>dp(n+1,0);
  for(ll i=1;i<=n;i++){
  	ll ind=lower_bound(temp.begin(),temp.end(),arr[i-1].first)-temp.begin();
	--ind;
	dp[i]=max(arr[i-1].second.second+dp[ind+1],dp[i-1]);
  }
  cout<<dp[n]<<"\n";
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
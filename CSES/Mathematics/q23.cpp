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
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(ll &x:arr){
  	cin>>x;
  }
  long double ans=0.0;
  for(ll i=0;i<n;i++){
  	for(ll j=i+1;j<n;j++){
  		ll ri=arr[i],rj=arr[j];
  		if(ri<=rj){
  			ll val=ri-1;
  			ans+=(long double)val/(2.0*rj);
  		}
  		else{
  			ll val=2*ri-rj-1;
  			ans+=(long double)val/(2.0*ri);
  		}
  	}
  }
  printf("%.6f\n",ans);
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

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
  vector<ll>arr(n+1),pre(n+1);
  for(ll i=1;i<=n;i++) cin>>arr[i];
  for(ll i=1;i<=n;i++) pre[i]=arr[i]+pre[i-1];
  ll q;
  cin>>q;
  auto findX=[&](ll a){
  	ll ind=upper_bound(pre.begin(),pre.end(),a)-pre.begin();
  	return ind-1;
  };
  auto isGreater=[&](ll l,ll r,ll u){
  	if(r==n) return false;
  	ll a=pre[l-1];
  	ll n1=pre[r+1]-a,n2=pre[r]-a;
  	ll val1=(n1*(2*u+1-n1))/2;
  	ll val2=(n2*(2*u+1-n2))/2;
  	return val1>val2;
  };
  while(q--){
  	ll l,u;
  	cin>>l>>u;
  	ll a=pre[l-1];
  	ll z=u+a;
  	ll ans=max(l,findX(z));
  	if(isGreater(l,ans,u)) ans++;
  	cout<<ans<<" \n"[q==0];
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
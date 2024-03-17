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
vector<ll>pre;
ll findRangeSum(ll l,ll r){
	if(l==0) return pre[r];
	return pre[r]-pre[l-1];
}

void solve(){
  ll n,q;
  cin>>n>>q;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  pre.assign(n,0);
  pre[0]=arr[0];
  for(ll i=1;i<n;i++){
  	pre[i]=arr[i]+pre[i-1];
  }
  while(q--){
  	ll l,r;
  	cin>>l>>r;
  	--l;--r;
  	cout<<findRangeSum(l,r)<<endl;
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
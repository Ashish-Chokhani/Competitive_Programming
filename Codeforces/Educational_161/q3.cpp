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
  vector<ll>cities(n);
  for(auto &x:cities){
    cin>>x;
  }
  vector<ll>pre(n),suf(n);
  auto getNearest=[&](ll ind)->ll{
  	if(ind==0) return 1;
  	if(ind==n-1) return n-2;
  	return (abs(cities[ind]-cities[ind-1])<abs(cities[ind+1]-cities[ind]))?ind-1:ind+1;
  };
  pre[0]=0;
  for(ll i=0;i<n-1;i++){
  	if(getNearest(i)==i+1) pre[i+1]=1+pre[i];
  	else pre[i+1]=pre[i]+abs(cities[i+1]-cities[i]);
  }
  
  suf[n-1]=0;
  for(ll i=n-1;i>=1;i--){
  	if(getNearest(i)==i-1) suf[i-1]=1+suf[i];
  	else suf[i-1]=suf[i]+abs(cities[i-1]-cities[i]);
  }
  ll m;
  cin>>m;
  while(m--){
  	ll x,y;
  	cin>>x>>y;
  	--x;--y;
  	cout<<(x<y?(pre[y]-pre[x]):suf[y]-suf[x])<<endl;
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
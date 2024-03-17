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

ll binexp(ll a, ll b, ll m)
{
    if (b == 0)
        return 1ll;
    if (b == 1)
        return a % m;
    if (b % 2)
        return (a * binexp(a, b - 1, m)) % m;
    return binexp((a * a) % m, b / 2, m);
}

ll mod_inv(ll x)
{
    return binexp(x, mod - 2, mod)%mod;
}

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
  ll s=(n*(n+1))/2;
  if(s&1){
  	cout<<"0\n";
  	return;
  }
  vector<vector<ll>>dp(n+1,vector<ll>(s+1,0));
  vector<ll>prev(s+1,0);
  prev[0]=1;
  for(ll i=1;i<=n;i++){
  	vector<ll>cur(s+1,0);
  	cur[0]=1;
  	for(ll j=1;j<=s;j++){
  		cur[j]+=prev[j];
  		cur[j]%=mod;
  		if(j>=i) cur[j]+=prev[j-i];
  		cur[j]%=mod;
  	}
  	prev=cur;
  }
  cout<<(prev[s/2]*mod_inv(2))%mod<<"\n";
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
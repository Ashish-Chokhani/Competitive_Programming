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

ll firstSetBit(ll x){
	return log2(x&(-x));
}

void solve(){
  ll n,m;
  cin>>n>>m;
  map<pair<ll,ll>,ll>isEdge;
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	isEdge[{u,v}]=isEdge[{v,u}]=1;
  }
  vector<vector<ll>>dp((1LL<<n)+2,vector<ll>(n+2,0));
  for(ll i=0;i<n;i++){
  	dp[1LL<<i][i]=1;
  }
  for(ll mask=0;mask<(1LL<<n);mask++){
  	for(ll i=0;i<n;i++){
  		if(!((mask>>i)&1) || firstSetBit(mask)==i || __builtin_popcountll(mask)<=1) continue;
  		for(ll j=0;j<n;j++){
  			if((mask>>j)&1 && isEdge[{i,j}]){
  				dp[mask][i]+=dp[mask^(1LL<<i)][j];
  			}
  		}
  	}
  }
  ll ans=0;
  for(ll mask=0;mask<(1LL<<n);mask++){
  	if(__builtin_popcountll(mask)<3) continue;
  	ll j=firstSetBit(mask);
  	for(ll i=0;i<n;i++){
  		if(!isEdge[{j,i}]) continue;
  		ans+=dp[mask][i];
  	}
  }
  cout<<ans/2<<"\n";
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
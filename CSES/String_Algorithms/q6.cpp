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

ll maxN=150;

void solve(){
  ll n,q;
  cin>>n>>q;
  maxN=min(n,maxN);
  vector<ll>adj[maxN+1][maxN+1],sum[maxN+1][maxN+1][2];
  ll arr[n];
  for(ll i=0;i<n;i++){
  	cin>>arr[i];
  }
  for(ll i=1;i<=maxN;i++){
  	for(ll j=0;j<n;j++){
  		adj[i][j%i].push_back(arr[j]);
  	}
  }
  for(ll i=1;i<=maxN;i++){
  	for(ll start=0;start<i;start++){
  		if(adj[i][start].size()==0) continue;
  		sum[i][start][0].push_back(adj[i][start][0]);
  		sum[i][start][1].push_back(adj[i][start][0]);
  		for(ll j=1;j<adj[i][start].size();j++){
  			ll element=adj[i][start][j];
  			sum[i][start][0].push_back(adj[i][start][j]+sum[i][start][0][j-1]);
  			sum[i][start][1].push_back((j+1)*adj[i][start][j]+sum[i][start][1][j-1]);
  		}
  	}
  }
  auto rangeSum=[&](ll l,ll r,vector<ll>&pre)->ll{
  	ll val=pre[r];
  	if(l>=1) val-=pre[l-1];
  	return val;
  };
  
  while(q--){
  	ll s,d,k;
  	cin>>s>>d>>k;
  	if(d>=maxN){
  		ll ans=0,factor=1;
  		for(ll i=s-1;i<=s-1+(k-1)*d;i+=d){
  			ans+=factor*arr[i];
  			factor++;
  		}
  		cout<<ans<<" ";
  	}
  	else{
  		ll l=(s-1)/d;
	  	ll r=l+k-1;
	  	ll start=(s-1)%d;
	  	ll val=rangeSum(l,r,sum[d][start][1]);
	  	val-=l*rangeSum(l,r,sum[d][start][0]);
	  	cout<<val<<" ";
  	}
  }
  cout<<endl;
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
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

const ll maxN=205;
vector<ll>adj[maxN];
ll n;
ll dist[maxN][maxN];
ll dp[maxN][maxN];
ll binexp(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1) res*=a;
		res%=mod;
		a=a*a;
		a%=mod;
		n>>=1; 
	}
	return res;
}

ll modInv(ll n){
	return binexp(n,mod-2);
}

void DFS(ll u,ll par,ll start){
	for(ll v:adj[u]){
		if(v==par) continue;
		dist[start][v]=dist[start][u]+1;
		DFS(v,u,start);
	}
}

void solve(){
  ll n;
  cin>>n;
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  for(ll start=1;start<=n;start++){
  	dist[start][start]=0;
  	DFS(start,0,start);
  }
  for(ll i=0;i<=n;i++){
  	for(ll j=0;j<=n;j++){
  		if(i==0) dp[i][j]=1;
  		else if(j==0) dp[i][j]=0;
  		else dp[i][j]=modInv(2)*((dp[i][j-1]+dp[i-1][j])%mod);
  		dp[i][j]%=mod;
  	}
  }
  ll ans=0;
  for(ll i=1;i<=n;i++){
  	for(ll j=1;j<i;j++){
  		ll d=dist[i][j];
  		for(ll v=1;v<=n;v++){
  			ll x=(dist[i][v]-dist[v][j]+d)/2;
  			ans+=dp[x][d-x];
  			ans%=mod;
  		}
  	}
  }
  cout<<(ans*modInv(n))%mod<<endl;
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
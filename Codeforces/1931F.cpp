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

ll n,k;
const ll maxN=2e5+2;
vector<ll>adj[maxN+1];
vector<ll>vis(maxN+1,0);

bool detectCycle(ll cur){
  	vis[cur]=1;
  	for(auto it:adj[cur]){
  		if(!vis[it]){
  			if(detectCycle(it)) return true;
  		}
  		else if(vis[it]==1) return true;
  	}
  	vis[cur]=2;
  	return false;
}

void solve(){
  cin>>n>>k;
  for(ll i=0;i<=n;i++) adj[i].clear();
  for(ll i=0;i<=n;i++) vis[i]=0;
  ll prev=-1;
  for(ll i=0;i<k;i++){
  	for(ll j=0;j<n;j++){
  		ll u;
  		cin>>u;
  		if(j>=2) adj[prev].push_back(u);
  		prev=u;
  	}
  }
  for(ll i=1;i<=n;i++){
  	if(vis[i]) continue;
  	if(detectCycle(i)){
  		cout<<"NO\n";
  		return;
  	}
  }
  cout<<"YES\n";
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
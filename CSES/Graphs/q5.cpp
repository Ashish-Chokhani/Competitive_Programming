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

bool checkBipartite(ll u,vector<ll>&color,ll col,vector<ll>*adj){
	color[u]=col;
	for(auto it:adj[u]){
		if(color[it]==-1){
			if(checkBipartite(it,color,1-col,adj)) return true;
		}
		else if(color[it]==col) return true;
	}
	return false;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>adj[n+1];
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  vector<ll>color(n,-1);
  for(ll i=0;i<n;i++){
  	if(color[i]==-1){
  		if(checkBipartite(i,color,0,adj)){
  			cout<<"IMPOSSIBLE\n";
  			return;
  		}
  	}
  }
  for(ll i=0;i<n;i++){
  	cout<<color[i]+1<<" ";
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
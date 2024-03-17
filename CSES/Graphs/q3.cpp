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

void DFS(ll u,vector<ll>*adj,ll head,vector<ll>&vis){
	vis[u]=1;
	for(auto it:adj[u]){
		if(!vis[it]){
			DFS(it,adj,head,vis);
		}
	}
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
  vector<ll>vis(n+1,0);
  ll nComponents=0;
  vector<ll>ans;
  for(ll i=0;i<n;i++){
  	if(!vis[i]){
  		nComponents++;
  		ans.push_back(i);
  		DFS(i,adj,i,vis);
  	}
  }
  cout<<nComponents-1<<"\n";
  if(nComponents==1){
  	return;
  }
  for(ll i=1;i<(ll)ans.size();i++){
  	cout<<ans[i-1]+1<<" "<<ans[i]+1<<"\n";
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
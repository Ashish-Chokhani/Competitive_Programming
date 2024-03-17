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

const ll max_N=2e5+2;
vector<ll>adj[max_N];
set<ll>colors[max_N];
vector<ll>ans(max_N);

void DFS(ll cur,ll par){
	for(auto child:adj[cur]){
		if(child==par) continue;
		DFS(child,cur);
		if(colors[cur].size()<colors[child].size()) swap(colors[cur],colors[child]);
		for(ll color:colors[child]) colors[cur].insert(color);
	}
    ans[cur]=colors[cur].size();
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(ll i=0;i<n;i++){
  	ll x;
    cin>>x;
    colors[i].insert(x);
  }
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  DFS(0,-1);
  for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
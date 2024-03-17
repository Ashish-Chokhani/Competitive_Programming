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

const ll maxN=2e5+2;
vector<ll>adj[maxN];
vector<ll>subtree;

void DFS(ll cur,ll par){
	subtree[cur]=1;
	for(auto child:adj[cur]){
		if(child==par) continue;
		DFS(child,cur);
		subtree[cur]+=subtree[child];
	}
}

void solve(){
  ll n;
  cin>>n;
  subtree.resize(n,0);
  for(ll i=0;i<n-1;i++){
  	ll v;
  	cin>>v;
  	--v;
  	adj[i+1].push_back(v);
  	adj[v].push_back(i+1);
  }
  DFS(0,-1);
  for(ll i=0;i<n;i++) cout<<subtree[i]-1<<" ";
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
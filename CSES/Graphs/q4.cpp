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
  queue<pair<ll,ll>>q;
  vector<ll>parent(n+1,-1),vis(n+1,0);
  q.push({0,n-1});
  vis[0]=1;
  while(!q.empty()){
  	ll node=q.front().first;
  	ll dis=q.front().second;
  	q.pop();
  	for(auto it:adj[node]){
  		if(vis[it]) continue;
  		vis[it]=1;
  		q.push({it,dis+1});
  		parent[it]=node;
  	}
  }
  if(parent[n-1]==-1){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  vector<ll>ans;
  ll pos=n-1;
  while(pos!=0){
  	ans.push_back(pos);
  	pos=parent[pos];
  }
  ans.push_back(0);
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<"\n";
  for(auto it:ans){
  	cout<<it+1<<" ";
  }
  cout<<"\n";
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
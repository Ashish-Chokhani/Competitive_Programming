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

void solve(){
  ll n;
  cin>>n;
  string s[2];
  cin>>s[0]>>s[1];
  vector<ll>adj[2*n];
  ll dx[4]={-1,0,0,1};
  ll dy[4]={0,-1,1,0};
  auto isValid=[&](ll x,ll y){
  	return x>=0 && x<2 && y>=0 && y<n;
  };
  auto findNode=[&](ll i,ll j){
  	return i*n+j;
  };
  auto where=[&](ll x,ll y)->pair<ll,ll>{
  	if(s[x][y]=='<') return {x,y-1};
  	return {x,y+1};
  };
  for(ll i=0;i<2;i++){
  	for(ll j=0;j<n;j++){
  		ll node=findNode(i,j);
  		for(ll dir=0;dir<4;dir++){
  			ll new_x=i+dx[dir];
  			ll new_y=j+dy[dir];
  			if(!isValid(new_x,new_y)) continue;
  			auto coord=where(new_x,new_y);
  			ll x=coord.first;
  			ll y=coord.second;
  			auto to_node=findNode(x,y);
  			adj[node].push_back(to_node);
  		}
  	}
  }
  vector<ll>vis(2*n,0);
  function<void(ll)>DFS=[&](ll cur){
  	vis[cur]=1;
  	for(auto it:adj[cur]){
  		if(!vis[it]) DFS(it);
  	}
  };
  DFS(0);
  cout<<(vis[2*n-1]?"YES\n":"NO\n");
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
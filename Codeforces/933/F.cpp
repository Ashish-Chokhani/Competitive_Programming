#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e12;
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

struct Node{
	ll cur,par,color;
	Node(ll _cur,ll _par,ll _color){
		cur=_cur,par=_par,color=_color;
	}
};

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,ll>>adj[n];
  for(ll i=0;i<m;i++){
  	ll u,v,c;
  	cin>>u>>v>>c;
  	--u;--v;
  	adj[u].push_back({v,c});
  	adj[v].push_back({u,c});
  }
  ll b,e;
  cin>>b>>e;
  --b;--e;
  map<pair<ll,ll>,ll>weights;
  vector<ll>vis(n,0);
  vis[b]=1;
  queue<Node>q;
  q.push(Node(b,-1,-1));
  while(!q.empty()){
  	ll cur=q.front().cur;
  	ll par=q.front().par;
  	ll color=q.front().color;
  	q.pop();
  	for(auto it:adj[cur]){
  		
  	}
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
    cin >> t;
    ll cnt=0;
    while (t--)
    {
    	// cnt++;
    	// if(cnt==67){
    	// 	  ll n,m;
			  // cin>>n>>m;
			  // cout<<n<<"."<<m<<".";
			  // for(ll i=0;i<m;i++){
			  // 	ll u,v,c;
			  // 	cin>>u>>v>>c;
			  // 	cout<<u<<"."<<v<<"."<<c<<".";
			  // }
			  // ll b,e;
			  // cin>>b>>e;
			  // cout<<b<<"."<<e<<".";
    	// }
    	//else
        solve();
    }
    return 0;
}
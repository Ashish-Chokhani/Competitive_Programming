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

class TreeAncestor{
	vector<vector<ll>>up;
	ll LOG;
public:
	TreeAncestor(ll n,vector<ll>parent){
		LOG=0;
		while(1LL<<(LOG+1)<=n){
			LOG++;
		}
		up=vector<vector<ll>>(n,vector<ll>(LOG+1));
		for(ll v=0;v<n;v++){
			up[v][0]=parent[v]; //The left order of run of for loop is possible only when parent[i]<i
			for(ll j=1;j<=LOG;j++){
				if(up[v][j-1]!=-1) up[v][j]=up[up[v][j-1]][j-1];
				else up[v][j]=-1;
			}
		}
	}
public:
	ll getKthAncestor(ll k,ll node){
		for(ll j=0;j<=LOG;j++){
			if(k&(1<<j)) node=up[node][j];
			if(node==-1) return -1;
		}
		return node;
	}
};

const ll maxN=2e5+2;
vector<ll>paren;
vector<ll>adj[maxN];

void DFS(ll cur,ll par){
	paren[cur]=par;
	for(ll child:adj[cur]){
		if(child==par) continue;
		DFS(child,cur);
	}
}


void solve(){
  ll n,q;
  cin>>n>>q;
  paren.resize(n+4,0);
  for(ll i=0;i<n-1;i++){
  	ll u;
  	cin>>u;
  	--u;
  	adj[u].push_back(i+1);
  	adj[i+1].push_back(u);
  }
  DFS(0,-1);
  TreeAncestor Tree(n,paren);
  while(q--){
  	ll x,k;
  	cin>>x>>k;
  	--x;
  	ll val=Tree.getKthAncestor(k,x);
  	if(val!=-1) val++;
  	cout<<val<<endl;
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
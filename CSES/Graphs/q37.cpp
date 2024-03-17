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
const ll maxN=3e5+2,maxM=3e5+2;
vector<ll>adj[maxN],adjT[maxN];
stack<ll>order;
vector<bool>vis;
vector<ll>comp_id,assignment;
ll n,m,id;

//Adjust the value of n

void dfs1(ll cur){
	vis[cur]=1;
	for(ll to:adj[cur]){
		if(vis[to]) continue;
		dfs1(to);
	}
	order.push(cur);
}

void dfs2(ll cur,ll &id){
	comp_id[cur]=id;
	for(ll to:adjT[cur]){
		if(comp_id[to]==-1)
			dfs2(to,id);
	}
}

bool solve_2Sat(){
	vis.assign(n,false);
	comp_id.assign(n,-1);
	id=0;
	for(ll i=0;i<n;i++){
		if(!vis[i]) dfs1(i);
	}
	while(!order.empty()){
		ll node=order.top();
		order.pop();
		if(comp_id[node]==-1) dfs2(node,++id);
	}
	assignment.assign(n/2,0);
	for(ll i=0;i<n;i+=2){
		if(comp_id[i]==comp_id[i+1]) return false;
		assignment[i/2]=comp_id[i]>comp_id[i+1];
	}
	return true;
}

void add_disjunction(bool na,ll a,bool nb,ll b){
	a=(2*a)^na;
	b=(2*b)^nb;
	ll neg_a=a^1;
	ll neg_b=b^1;
	adj[neg_a].push_back(b);
	adj[neg_b].push_back(a);
	adjT[b].push_back(neg_a);
	adjT[a].push_back(neg_b);
}

void solve(){
  cin>>m>>n;
  n=n*2;
  char edge[2];
  ll val[2];
  for(ll i=0;i<m;i++){
  	cin>>edge[0]>>val[0]>>edge[1]>>val[1];
  	add_disjunction(edge[0]!='+',val[0]-1,edge[1]!='+',val[1]-1);
  }
  if(!solve_2Sat()){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  for(ll &v:assignment){
  	cout<<((v==1)?'+':'-');
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
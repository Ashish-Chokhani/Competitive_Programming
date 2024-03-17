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
vector<ll>sub_sz(maxN,0),vis(maxN,0),cnt(maxN,0);
ll ans=0,n,k,maxd;
 
void calcSubtreeSize(ll u,ll par){
	sub_sz[u]=1;
	for(ll child:adj[u]){
		if(!vis[child] && child!=par){
			calcSubtreeSize(child,u);
			sub_sz[u]+=sub_sz[child];
		}
	}
}
 
ll findCentroid(ll u,ll par,ll treeSize){
	for(ll child:adj[u]){
		if(!vis[child] && child!=par && sub_sz[child]>treeSize){
			return findCentroid(child,u,treeSize);
		}
	}
	return u;
}
 
void DFS(ll u,ll par,ll d,bool isCalculate){
	if(d>k) return;
	if(isCalculate){
		ans+=cnt[k-d];
	}
	else{
		cnt[d]++;
	}
	maxd=max(maxd,d);
	for(ll child:adj[u]){
		if(!vis[child] && child!=par) DFS(child,u,d+1,isCalculate);
	}
}
 
void centroid_decompose(ll  u,ll par){
	calcSubtreeSize(u,-1);
	ll centroid=findCentroid(u,par,sub_sz[u]>>1);
	vis[centroid]=1;
	cnt[0]=1;
	maxd=0;
	
	for(ll child:adj[centroid]){
		if(!vis[child]){
			DFS(child,centroid,1,true);
			DFS(child,centroid,1,false);
		}
	}
	
	fill(cnt.begin(), cnt.begin()+maxd+10, 0);
	for(ll child:adj[centroid]){
		if(!vis[child]) centroid_decompose(child,centroid);
	}
}
 
 
void solve(){
	cin>>n>>k;
	for(ll i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid_decompose(0,-1);
	cout<<ans<<endl;
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
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

class DSU{
	vector<ll>parent,rank;
public:
	DSU(ll n){
		for(ll i=0;i<n;i++){
			parent.push_back(i);
			rank.push_back(0);
		}
	}
public:
	ll findPar(ll u){
		if(parent[u]==u) return u;
		return parent[u]=findPar(parent[u]);
	}
public:
	bool isSameComponent(ll u,ll v){
		return findPar(u)==findPar(v);
	}
public:
	void unionByRank(ll u,ll v){
		ll paru=findPar(u);
		ll parv=findPar(v);
		if(isSameComponent(u,v)) return;
		if(rank[paru]<rank[parv]) parent[paru]=parv;
		else if(rank[paru]>rank[parv]) parent[parv]=paru;
		else{
			parent[paru]=parv;
			rank[parv]++;
		}
	}
public:
	ll countComponents(){
		set<ll>st;
		ll n=parent.size();
		for(ll i=0;i<n;i++){
			st.insert(findPar(i));
		}
		return (ll)st.size();
	}
};

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,pair<ll,ll>>>edges;
	for(ll i=0;i<m;i++){
		ll u,v,wt;
		cin>>u>>v>>wt;
		--u;--v;
		edges.push_back({wt,{u,v}});
	}
	DSU dsu(n);
	sort(edges.begin(),edges.end());
	ll ans=0;
	for(auto edge:edges){
		ll wt=edge.first;
		ll u=edge.second.first;
		ll v=edge.second.second;
		if(dsu.isSameComponent(u,v)) continue;
		ans+=wt;
		dsu.unionByRank(u,v);
	}
	if(dsu.countComponents()!=1){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	cout<<ans<<"\n";
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
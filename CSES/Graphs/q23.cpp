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
	vector<ll>parent,rank,componentSize;
	ll nComponents,maxComponentSize;
public:
	DSU(ll n){
		for(ll i=0;i<n;i++){
			parent.push_back(i);
			rank.push_back(0);
			componentSize.push_back(1);
		}
		nComponents=n;
		maxComponentSize=1;
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
		nComponents--;
		if(rank[paru]<rank[parv]){
			parent[paru]=parv;
			componentSize[parv]+=componentSize[paru];
			maxComponentSize=max(maxComponentSize,componentSize[parv]);
		}
		else if(rank[paru]>rank[parv]){
			parent[parv]=paru;
			componentSize[paru]+=componentSize[parv];
			maxComponentSize=max(maxComponentSize,componentSize[paru]);
		}
		else{
			parent[paru]=parv;
			rank[parv]++;
			componentSize[parv]+=componentSize[paru];
			maxComponentSize=max(maxComponentSize,componentSize[parv]);
		}
	}
public:
	ll countComponents(){
		return nComponents;
	}
public:
	ll findLargestComponent(){
		return maxComponentSize;
	}
};

void solve(){
	ll n,m;
	cin>>n>>m;
	DSU dsu(n);
	for(ll i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		--u;
		--v;
		dsu.unionByRank(u,v);
		cout<<dsu.countComponents()<<" "<<dsu.findLargestComponent()<<"\n";
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
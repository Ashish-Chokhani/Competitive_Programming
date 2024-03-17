#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
template<class T>void print(T x)
{
  cerr << x;
}
template<class T, class V>
         void print(pair<T , V> x)
{
  print(x.first); 
  cerr << ':';
  print(x.second);
}
template<class T>
         void print(vector<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T,
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T, 
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(unordered_set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T, class V>
         void print(vector<pair<T, V>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x.first);
    cerr << ":"; 
    print(x.second);
    cerr << ' ';
  }
  cerr << ']';
}
template <class T, class V> 
          void print(map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T, class V> 
          void print(unordered_map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T> 
          void print(vector<vector<T>> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}


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

void DFS(ll cur,ll par,vector<ll>&vis,vector<ll>*adj,vector<ll>&parent,ll &cyclic_id,vector<ll>*cyclic_nodes,map<ll,pair<ll,ll>>&whichCyclicId,vector<bool>&isCyclic){
	vis[cur]=1;
	parent[cur]=par;
	for(auto it:adj[cur]){
		if(vis[it]==2) continue;
		else if(!vis[it]) DFS(it,cur,vis,adj,parent,cyclic_id,cyclic_nodes,whichCyclicId,isCyclic);
		else{
			ll temp=cur;
			while(temp!=it){
				cyclic_nodes[cyclic_id].push_back(temp);
				whichCyclicId[temp]={cyclic_id,cyclic_nodes[cyclic_id].size()-1};
				isCyclic[temp]=true;
				temp=parent[temp];
			}
			cyclic_nodes[cyclic_id].push_back(it);
			whichCyclicId[it]={cyclic_id,cyclic_nodes[cyclic_id].size()-1};
			isCyclic[it]=true;
			cyclic_id++;
		}
	}
	vis[cur]=2;
}

ll findKthCyclicNode(map<ll,pair<ll,ll>>&whichCyclicId,vector<ll>*cyclic_nodes,ll k,ll node){
	ll id=whichCyclicId[node].first;
	ll pos=whichCyclicId[node].second;
	ll sz=cyclic_nodes[id].size();
	return cyclic_nodes[id][(k+pos)%sz];
}

ll findKthLinearNode(map<ll,pair<ll,ll>>&whichCyclicId,map<ll,pair<ll,ll>>&whichLinearId,map<ll,pair<ll,ll>>&lastLinearNode,vector<ll>*linear_nodes,vector<ll>*cyclic_nodes,ll k,ll node){
	ll id=whichLinearId[node].first;
	ll pos=whichLinearId[node].second;
	ll sz=linear_nodes[id].size();
	if(k+pos<=sz-1) return cyclic_nodes[id][k+pos];
	else if(k+pos==sz) return lastLinearNode[id].second;
	return findKthCyclicNode(whichCyclicId,cyclic_nodes,sz-k-pos,lastLinearNode[id].second);
}

void solve(){
  ll n,q;
  cin>>n>>q;
  vector<ll>adj[n+1];
  vector<ll>indegree(n,0),next(n);
  for(ll i=0;i<n;i++){
  	ll u;
  	cin>>u;
  	--u;
  	adj[i].push_back(u);
  	indegree[u]++;
  	next[i]=u;
  }
  ll cyclic_id=0,linear_id=0;
  vector<ll>cyclic_nodes[n+1],linear_nodes[n+1];
  vector<ll>vis(n,0),parent(n,-1);
  map<ll,pair<ll,ll>>whichCyclicId,whichLinearId,lastLinearNode;;
  vector<bool>isCyclic(n,false);
  for(ll i=0;i<n;i++){
  	if(!vis[i]) DFS(i,-1,vis,adj,parent,cyclic_id,cyclic_nodes,whichCyclicId,isCyclic);
  }
  for(ll i=0;i<n;i++){
  	if(indegree[i]!=0) continue;
  	ll node=i,last=i;
  	while(isCyclic[node]!=true){
  		linear_nodes[linear_id].push_back(node);
  		last=node;
  		whichLinearId[node]={linear_id,linear_nodes[linear_id].size()-1};
  		node=next[node];
  	}
  	lastLinearNode[linear_id]={last,node};
  	linear_id++;
  }
  while(q--){
  	ll u,k;
  	cin>>u>>k;
  	--u;
  	if(isCyclic[u]) cout<<findKthCyclicNode(whichCyclicId,cyclic_nodes,k,u)+1<<"\n";
  	else cout<<findKthLinearNode(whichCyclicId,whichLinearId,lastLinearNode,linear_nodes,cyclic_nodes,k,u)+1<<"\n";
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
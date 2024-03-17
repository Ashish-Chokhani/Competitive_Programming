#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const ll mod = 1000000007; //998244353
//const ll INF = 1e18;
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
vector<vector<ll>>cycles;
bool foundCycle=false;

void detectCycles(ll cur,ll par,vector<ll>&parent,vector<ll>&vis,vector<ll>*adj){
	parent[cur]=par;
	vis[cur]=1;
	for(auto it:adj[cur]){
		if(it==parent[cur]) continue;
		if(!vis[it]) detectCycles(it,cur,parent,vis,adj);		
		else if(vis[it]==1 && !foundCycle){
			foundCycle=true;
			vector<ll>v;
			ll u=cur;
			while(u!=it){
				v.push_back(u);
				u=parent[u];
			}
			v.push_back(it);
			cycles.push_back(v);
		}
	}
	vis[cur]=2;
}

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
  vector<ll>vis(n,0);
  vector<ll>parent(n,-1);
  for(ll i=0;i<n;i++){
  	if(!vis[i]) detectCycles(i,-1,parent,vis,adj);
  }
  ll longestCycle=0,longestCycle_ind=-1;
  for(ll i=0;i<(ll)cycles.size();i++){
  	if((ll)cycles[i].size()>longestCycle){
  		longestCycle=cycles[i].size();
  		longestCycle_ind=i;
  	}
  }
  if(longestCycle<3){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  cout<<longestCycle+1<<"\n";
  for(auto it:cycles[longestCycle_ind]){
  	cout<<it+1<<" ";
  }
  cout<<cycles[longestCycle_ind][0]+1;
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
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
template<class T>
         void print(stack<T> &a)
{
  cerr << '[' << ' ';
  stack<T>temp=a;
  while(!temp.empty())
  {
    auto val=temp.top();
    temp.pop();
    print(val); 
    cerr << " ";
  }
  cerr << ']';
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

ll findFlow(ll s,ll t,vector<ll>*adj,vector<vector<ll>>&capacity,vector<ll>&parent){
	queue<pair<ll,ll>>q;
	for(ll i=0;i<(ll)parent.size();i++) parent[i]=-1;
	q.push({s,INF});
	parent[s]=-2;
	while(!q.empty()){
		ll cur=q.front().first;
		ll flow=q.front().second;
		q.pop();
		for(ll next:adj[cur]){
			if(parent[next]==-1 && capacity[cur][next]){
				parent[next]=cur;
				ll new_flow=min(flow,capacity[cur][next]);
				if(next==t) return new_flow;
				q.push({next,new_flow});
			}
		}
	}
	return 0;
}

ll calcMaxFlow(ll s,ll t,vector<ll>*adj,ll n,vector<vector<ll>>&capacity){
	ll flow=0,new_flow=0;
	vector<ll>parent(n,-1);
	while((new_flow=findFlow(s,t,adj,capacity,parent))){
		flow+=new_flow;
		ll cur=t;
		while(cur!=s){
			ll prev=parent[cur];
			capacity[prev][cur]-=new_flow;
			capacity[cur][prev]+=new_flow;
			cur=prev;
		}
	}
	return flow;
}

// void DFS(ll cur,vector<ll>*adj,vector<ll>&vis,vector<vector<ll>>&capacity){
//   vis[cur]=1;
//   cout<<cur<<endl;
//   for(auto it:adj[cur]){
//     if(vis[it] || capacity[cur][it]==0) continue;
//     DFS(it,adj,vis,capacity);
//   }
// }

void solve(){
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll>adj[n+m+4];
  vector<vector<ll>>capacity(n+m+4,vector<ll>(m+n+4,0));
  map<pair<ll,ll>,ll>isEdge;
  for(ll i=0;i<k;i++){
  	ll u,v;
  	cin>>u>>v;
  	adj[u].push_back(v+n);
  	adj[v+n].push_back(u);
  	capacity[u][v+n]=1;
    //capacity[v][u]=1;
    isEdge[{u,v+n}]=1;
  }
  for(ll i=1;i<=n;i++){
    adj[0].push_back(i);
    adj[i].push_back(0);
    capacity[0][i]=1;
    //capacity[v][u]=1;
    isEdge[{0,i}]=1;
  }
  for(ll i=n+1;i<=n+m;i++){
    adj[i].push_back(n+m+1);
    adj[n+m+1].push_back(i);
    capacity[i][n+m+1]=1;
    //capacity[v][u]=1;
    isEdge[{i,n+m+1}]=1;
  }
  ll s=0,t=n+m+1;
  cout<<calcMaxFlow(s,t,adj,n+m+4,capacity)<<endl;
  vector<ll>vis(n+m+2,0); 
  for(ll i=1;i<=n;i++){
    for(ll j=n+1;j<=n+m;j++){
      if(isEdge[{i,j}] && !capacity[i][j]){
        cout<<i<<" "<<j-n<<endl;
      }
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
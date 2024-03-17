#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e12;
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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>>grid(n,vector<ll>(m));
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<m;j++) cin>>grid[i][j];
  }
  auto isSafeDownwards=[&](ll x,ll y)->bool{
  	return grid[(x+1)%n][y]==0 && grid[(x+2)%n][y]==0;
  };
  auto isSafeRight=[&](ll x,ll y)->bool{
  	return y<m-1 && grid[(x+1)%n][y+1]==0;
  };
  queue<pair<ll,ll>>q;
  q.push({0,0});
  vector<vector<ll>>dist(n,vector<ll>(m,INF));
  dist[0][0]=0;
  while(!q.empty()){
  	ll x=q.front().first;
  	ll y=q.front().second;
  	q.pop();
  	pair<ll,ll> delta[2]={{2,0},{1,1}};
  	for(ll i=0;i<2;i++){
  		pair<ll,ll>d=delta[i];
  		ll newX=(x+d.first)%n;
  		ll newY=y+d.second;
  		if(i==0 && isSafeDownwards(x,y) && dist[newX][newY]>1+dist[x][y]){
  			dist[newX][newY]=min(1+dist[x][y],dist[newX][newY]);
  			q.push({newX,newY});
  		}
  		if(i==1 && isSafeRight(x,y) && dist[newX][newY]>1+dist[x][y]){
  			dist[newX][newY]=min(1+dist[x][y],dist[newX][newY]);
  			q.push({newX,newY});
  		}
  	}
  }
  ll ans=INF;
  debug(dist);
  for(ll i=0;i<n;i++){
  	ll curLoc=((i-dist[i][m-1])%n+n)%n;
  	cout<<curLoc<<" "<<dist[i][m-1]<<endl;
  	ans=min(ans,dist[i][m-1]+((curLoc+1)%n));
  }
  cout<<(ans==INF?-1:ans)<<endl;
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
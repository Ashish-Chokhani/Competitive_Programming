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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

struct Node{
	ll max_money,x,y,cur_money,op;
	Node(ll _maxMoney,ll _x,ll _y,ll _curMoney,ll _op){
		max_money=_maxMoney,x=_x,y=_y,cur_money=_curMoney,op=_op;
	}
};

void solve(){
  ll n;
  cin>>n;
  ll p[n][n];
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<n;j++) cin>>p[i][j];
  }
  ll r[n][n-1];
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<n-1;j++) cin>>r[i][j];
  }
  ll d[n-1][n];
  for(ll i=0;i<n-1;i++){
  	for(ll j=0;j<n;j++) cin>>d[i][j];
  }
  struct CompareNode {
    bool operator()(const Node &a, const Node &b) {
        // Comparison based on max_money in decreasing order
        return a.max_money < b.max_money;
    }
  };
  const ll maxN=4;
  ll howmany_op[maxN][maxN];
  for(ll i=0;i<maxN;i++) for(ll j=0;j<maxN;j++) howmany_op[i][j]=INF;
  howmany_op[0][0]=0;
  priority_queue<Node,vector<Node>, CompareNode> q;
  q.push(Node(p[0][0],0,0,0,0));
  
  auto isValid=[&](ll i,ll j){
  	return i>=0 && j>=0 && i<n && j<n; //remove !vis[i][j]
  };
  ll ans=INF;
  ll cnt=1;
  while(!q.empty()){
  	ll x=q.top().x;
  	ll y=q.top().y;
  	ll max_money=q.top().max_money;
  	ll cur_money=q.top().cur_money;
  	ll op=q.top().op;
  	if(x==n-1 && y==n-1) ans=min(ans,op);
  	q.pop();
  	ll x1=x+1,y1=y;
  	ll x2=x,y2=y+1;
  	if(isValid(x1,y1)){
  		ll req_amount=max(0LL,d[x][y]-cur_money);
  		ll req_op=(req_amount+max_money-1)/max_money;
  		ll new_amount=cur_money-d[x][y]+(req_op*max_money);
  		if(howmany_op[x1][y1]>req_op+op+1){
  			q.push(Node(max(max_money,p[x1][y1]),x1,y1,new_amount,op+req_op+1));
  			//howmany_op[x1][y1]=req_op+op+1;
  		}
  	}
  	if(isValid(x2,y2)){
  		ll req_amount=max(0LL,r[x][y]-cur_money);
  		ll req_op=(req_amount+max_money-1)/max_money;
  		ll new_amount=cur_money-r[x][y]+(req_op*max_money);
  		if(howmany_op[x2][y2]>req_op+op+1){
	  		q.push(Node(max(max_money,p[x2][y2]),x2,y2,new_amount,op+req_op+1));
	  		//howmany_op[x2][y2]=req_op+op+1;
  	    }
  	}
  }
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
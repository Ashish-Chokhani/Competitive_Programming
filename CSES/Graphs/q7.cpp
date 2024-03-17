#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
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

bool isBoundary(ll i,ll j,ll n,ll m){
	if(i!=0 && j!=0 && i!=n-1 && j!=m-1) return false;
	return true;
}

bool isValid(ll i,ll j,ll n,ll m,vector<vector<ll>>&vis,vector<string>&arr){
	return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && arr[i][j]=='.';
}

char findChar(ll i,ll j,ll new_i,ll new_j){
	if(j==new_j && new_i<i) return 'D';
	else if(j==new_j && new_i>i) return 'U';
	else if(i==new_i && new_j<j) return 'R';
	return 'L';
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<string>arr(n);
  for(auto &s:arr){
  	cin>>s;
  }
  queue<pair<ll,pair<ll,ll>>>q;
  queue<pair<ll,pair<ll,ll>>>q_monsters;
  pair<ll,ll>pos;
  vector<vector<pair<ll,ll>>>parent(n,vector<pair<ll,ll>>(m,{-1,-1}));
  vector<vector<ll>>time_taken_by_monster(n,vector<ll>(m,INF)),vis_monster(n,vector<ll>(m,0));
  
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<m;j++){
  		if(arr[i][j]=='A') pos={i,j};
  		if(arr[i][j]=='M'){
  			q_monsters.push({i,{j,0}});
  			vis_monster[i][j]=1;
  		}
  	}
  }
  
  
  //debug(vis_monster);
  //For Monster
  while(!q_monsters.empty()){
  	ll i=q_monsters.front().first;
  	ll j=q_monsters.front().second.first;
  	ll time=q_monsters.front().second.second;
  	q_monsters.pop();
  	time_taken_by_monster[i][j]=time;
  	ll dx[]={-1,0,0,1};
  	ll dy[]={0,-1,1,0};
  	for(ll dir=0;dir<4;dir++){
  		ll newX=i+dy[dir];
  		ll newY=j+dx[dir];
  		if(isValid(newX,newY,n,m,vis_monster,arr)){
  			q_monsters.push({newX,{newY,time+1}});
  			time_taken_by_monster[newX][newY]=min(time_taken_by_monster[newX][newY],time+1);
  			vis_monster[newX][newY]=1;
  		}
  	}
  }
  
  bool foundBoundary=false;
  string ans="";
  //For person
  vector<vector<ll>>time_taken(n,vector<ll>(m,0)),vis(n,vector<ll>(m,0));
  q.push({pos.first,{pos.second,0}});
  vis[pos.first][pos.second]=1;
  while(!q.empty()){
  	ll i=q.front().first;
  	ll j=q.front().second.first;
  	ll time=q.front().second.second;
  	if(isBoundary(i, j, n, m)){
  		foundBoundary=true;
  		if(ans.length()==0){
  			pair<ll,ll>cur={i,j};
  			while(cur!=pos){
  				pair<ll,ll>prev_cur=cur;
  				cur=parent[cur.first][cur.second];
  				ans+=findChar(prev_cur.first,prev_cur.second,cur.first,cur.second);
  			}
  		}
  	}
  	q.pop();
  	time_taken[i][j]=time;
  	ll dx[]={-1,0,0,1};
  	ll dy[]={0,-1,1,0};
  	for(ll dir=0;dir<4;dir++){
  		ll newX=i+dy[dir];
  		ll newY=j+dx[dir];
  		if(isValid(newX,newY,n,m,vis,arr) && time+1<time_taken_by_monster[newX][newY]){
  			q.push({newX,{newY,time+1}});
  			parent[newX][newY]={i,j};
  			time_taken[newX][newY]=time+1;
  			vis[newX][newY]=1;
  		}
  	}
  }
  if(!foundBoundary){
  	cout<<"NO\n";
  	return;
  }
  cout<<"YES\n";
  cout<<ans.length()<<"\n";
  reverse(ans.begin(),ans.end());
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
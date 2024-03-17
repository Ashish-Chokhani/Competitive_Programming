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

bool isValid(ll i,ll j,vector<vector<ll>>&vis,vector<string>&arr){
  ll n=vis.size();
  ll m=vis[0].size();
  return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && arr[i][j]!='#';
}

pair<ll,ll>pos_B;
vector<vector<pair<ll,ll>>>parent(1004,vector<pair<ll,ll>>(1004,{-1,-1}));

void BFS(ll x,ll y,vector<vector<ll>>&vis,vector<string>&arr){
  queue<pair<ll,ll>>q;
  vis[x][y]=1;
  q.push({x,y});
  ll dx[]={-1,0,0,1};
  ll dy[]={0,-1,1,0};
  while(!q.empty()){
    ll i=q.front().first;
    ll j=q.front().second;
    q.pop();
    for(ll dir=0;dir<4;dir++){
    ll newX=i+dy[dir];
    ll newY=j+dx[dir];
      if(isValid(newX,newY,vis,arr)){
        parent[newX][newY]={i,j};
        q.push({newX,newY});
        vis[newX][newY]=1;
      }
    }
  }
}

ll findChar(ll i,ll j,ll new_i,ll new_j){
  if(new_i==i && new_j<j) return 'R';
  else if(new_j==j && new_i<i) return 'D';
  else if(new_j==j && new_i>i) return 'U';
  return 'L';
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<string>arr(n);
  for(string &s:arr){
    cin>>s;
  }
  vector<vector<ll>>vis(n,vector<ll>(m,0));
  pair<ll,ll>pos,pos_A;
  
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      if(arr[i][j]=='A'){
        BFS(i,j,vis,arr);
        pos_A={i,j};
      }
      if(arr[i][j]=='B') pos_B={i,j};
    }
  }
  if(!vis[pos_B.first][pos_B.second]){
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
  string ans="";
  pos=pos_B;
  while(pos!=pos_A){
    pair<ll,ll>par=parent[pos.first][pos.second];
    char ch=findChar(pos.first,pos.second,par.first,par.second);
    ans+=ch;
    pos=par;
  }
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<"\n";
  for(char &ch:ans) cout<<ch;
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
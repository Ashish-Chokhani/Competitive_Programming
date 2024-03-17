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

void solve(){
  ll H,W,N;
  cin>>H>>W>>N;
  string t;
  cin>>t;
  vector<string>grid;
  for(ll i=0;i<H;i++){
  	string s;
  	cin>>s;
  	grid.push_back(s);
  }
  
  ll dx[4]={-1,0,0,1};
  ll dy[4]={0,-1,1,0};
  
  auto findCorresponding=[&](char move)->ll{
  	if(move=='L') return 1;
  	if(move=='R') return 2;
  	if(move=='U') return 0;
  	return 3;
  };
  
  auto isValid=[&](ll a,ll b)->bool{
  	return a>=0 && a<H && b>=0 && b<W;
  };
  auto isSeaEncountered=[&](ll a,ll b)->bool{
  	for(ll i=0;i<N;i++){
  		ll pos=findCorresponding(t[i]);
  		a+=dx[pos];
  		b+=dy[pos];
  		if(!isValid(a,b) || grid[a][b]=='#') return true;
  	}
  	return false;
  };
  ll ans=0;
  for(ll i=0;i<H;i++){
  	for(ll j=0;j<W;j++){
  		if(grid[i][j]=='#') continue;
  		ans+=!isSeaEncountered(i,j);
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
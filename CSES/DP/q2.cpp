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

void solve(){
  ll n,x;
  cin>>n>>x;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  vector<ll>prev(x+1,INF),cur(x+1,INF);
  prev[0]=cur[0]=0;
  for(ll i=1;i<=n;i++){
  	for(ll j=1;j<=x;j++){
  		ll val=INF;
  		if(j>=arr[i-1]) val=1+cur[j-arr[i-1]];
  		cur[j]=min(prev[j],val);
  	}
  	prev=cur;
  }
  if(cur[x]==INF) cur[x]=-1;
  cout<<cur[x]<<"\n";
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
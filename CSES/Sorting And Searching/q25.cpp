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

ll findMod(ll val,ll n){
  ll req=(abs(val)+n-1)/n;
  val+=req*n;
  return val%n;
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  vector<ll>pre(n,0);
  pre[0]=arr[0];
  for(ll i=1;i<n;i++){
  	pre[i]=arr[i]+pre[i-1];
  }
  map<ll,ll>mp;
  mp[0]++;
  ll ans=0;
  for(ll i=0;i<n;i++){
  	ll req=findMod(pre[i],n);
  	ans+=mp[req];
  	mp[findMod(pre[i],n)]++;
  }
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
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
  ll n;
  cin>>n;
  vector<ll>arr(n);
  ll ans=0,maxi=0;
  for(auto &x:arr){
    cin>>x;
  }
  for(auto &num:arr){
  	maxi=max(num,maxi);
  	ans+=max(0LL,maxi-num);
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
    t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
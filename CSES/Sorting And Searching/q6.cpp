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
  vector<pair<ll,ll>>intervals(n);
  
  for(pair<ll,ll>&interval : intervals){
  	cin>>interval.first>>interval.second;
    --interval.second;
  }
  sort(intervals.begin(),intervals.end(),[](pair<ll,ll>&i1,pair<ll,ll>&i2){
    return (i1.second<i2.second || (i1.second<i2.second && i1.first<=i2.first));
  });
  ll cur_r=0,ans=0;
  for(pair<ll,ll>interval:intervals){
    ll l=interval.first;
    ll r=interval.second;
    if(l>cur_r){
      ans++;
      cur_r=r;
    }
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
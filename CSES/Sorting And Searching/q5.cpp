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
  vector<pair<ll,char>>data;
  for(pair<ll,ll>&interval : intervals){
  	cin>>interval.first>>interval.second;
  	data.push_back({interval.first,'x'});
  	data.push_back({interval.second,'y'});
  }
  sort(data.begin(),data.end());
  int ans=0,cnt=0;
  for(auto &interval:data){
  	if(interval.second=='x') cnt++;
  	else cnt--;
  	ans=max(ans,cnt);
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
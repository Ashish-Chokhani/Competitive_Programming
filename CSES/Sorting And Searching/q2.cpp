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
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll>desired(n),available(m);
  for(auto &num:desired){
  	cin>>num;
  }
  for(auto &num:available){
  	cin>>num;
  }
  multiset<ll>st;
  for(auto &num:available){
  	st.insert(num);
  }
  int ans=0;
  sort(desired.begin(),desired.end());
  for(auto &num:desired){
  	ll l=num-k;
  	ll r=num+k;
  	auto val=st.lower_bound(l);
  	if(val != st.end() && *val<=r){
  		ans++;
  		st.erase(val);
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
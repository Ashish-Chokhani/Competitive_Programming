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
  for(auto &x:arr){
    cin>>x;
  }
  reverse(arr.begin(),arr.end());
  multiset<ll>st;
  int ans=0;
  for(auto &cube:arr){
  	if(st.empty()){
  		st.insert(cube);
  		ans++;
  		continue;
  	}
  	auto it=st.lower_bound(cube);
  	if(it==st.begin()){
  		st.insert(cube);
  		ans++;
  		continue;
  	}
  	--it;
  	st.erase(it);
  	st.insert(cube);
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
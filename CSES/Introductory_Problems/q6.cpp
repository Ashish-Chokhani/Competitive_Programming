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
  ll x,y;
  cin>>x>>y;
  ll row=max(x,y);
  ll ans=(row-1)*(row-1);
  if(row&1){
  	if(y<row){
  		ans+=y;
  	}
  	else{
  		ans+=2*row-x;	
  	}
  }
  else{
  	if(x<row){
  		ans+=x;
  	}
  	else{
  		ans+=2*row-y;	
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
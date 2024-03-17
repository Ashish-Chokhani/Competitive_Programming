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

bool isSecondHalf(ll val,ll ind){
	return (ind+1)>(val/2);
}

void solve(){
  ll n;
  cin>>n;
  vector<string>ans(1LL<<n);
  for(auto &s:ans){
  	string temp="";
  	for(ll i=0;i<n;i++){
  		temp+='0';
  	}
  	s=temp;
  }
  for(int bits=1;bits<=n;bits++){
  	ll val=1LL<<bits;
  	int cur_bit=n-bits;
  	bool reverse=false;
  	ll ind=0,cnt=0;
  	while(cnt<(1LL<<n)){
  		if((isSecondHalf(val,ind) && !reverse) || (!isSecondHalf(val,ind) && reverse)){
  			ans[cnt][cur_bit]='1';
  		}
  		cnt++;
  		ind++;
  		if(ind%(1LL<<bits)==0){
  			reverse=!reverse;
  			ind=0;
  		}
  	}
  }
  for(auto &s:ans){
  	cout<<s<<"\n";
  }
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
    while (t--)
    {
        solve();
    }
    return 0;
}
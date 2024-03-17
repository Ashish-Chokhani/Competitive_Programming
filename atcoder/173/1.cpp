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

ll fun(ll i,ll bound,ll last,string &s,ll len){
	if(i>=len) return 1;
	ll val=0;
	for(ll j=0;j<10;j++){
		if((i==0 && j==0) || j==last) continue;
		if(bound && j>s[i]-'0') continue;
		val+=fun(i+1,bound==1?(j==s[i]-'0'):0,j,s,len);
	}
	return val;
}

void solve(){
  ll k;
  cin>>k;
  // Keeep inside function
  // Count the number of good numbers <=k
  auto cntGood=[&](ll n){
  	ll cur=1,cnt=0,till=0;
  	while((till*10)+9<=k){
  	cur*=9;
  	cnt+=cur;
  	till=till*10+9;
    }
    string s=to_string(n);
    ll l=s.length();
    ll dp[l+1][2];
    memset(dp,0,sizeof(dp));
    dp[l][0]=dp[l][1]=1;
    for(ll i=l-1;i>=0;i--){
    	for(ll j=0;j<=1;j++){
    		
    	}
    }
  };
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
    //t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
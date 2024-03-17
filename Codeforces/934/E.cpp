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
const ll MOD = 1e9 + 9;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

void solve(){
  ll n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<ll>differ(n);
  differ[n-1]=differ[n-2]=n;
  for(ll i=n-3;i>=0;i--){
  	if(s[i]==s[i+2]) differ[i]=differ[i+2];
  	else differ[i]=i+2;
  }
  vector<ll>a(n);
  for(ll i=0;i<n;i++) a[i] = s[i] - 'a';
	vector<ll>hash_pfx(n, 0), hash_sfx(n, 0), pow31(n, 1);
	for(ll i=1;i<n;i++) pow31[i] = (pow31[i-1]*31)%MOD;
	for(ll i=0;i<n;i++) {
	    hash_pfx[i] = (i > 0 ? hash_pfx[i-1] : 0) + (a[i]*pow31[i])%MOD;
	    hash_pfx[i] %= MOD;
	}
	for (ll i = n-1; i >= 0; i--) {
	    hash_sfx[i] = (i < n-1 ? hash_sfx[i+1] : 0) + (a[i]*pow31[n-i-1])%MOD;
	    hash_sfx[i] %= MOD;
	}
	auto isPalindrome = [&](int l, int r) {
	    ll h1 = ((hash_pfx[r] - (l > 0 ? hash_pfx[l-1] : 0))%MOD + MOD)%MOD;
	    ll h2 = ((hash_sfx[l] - (r < n-1 ? hash_sfx[r+1] : 0))%MOD + MOD)%MOD;
	    h1 = (h1*pow31[n-r-1])%MOD;
	    h2 = (h2*pow31[l])%MOD;
	    return h1 == h2;
	};
  while(q--){
  	ll l,r;
  	cin>>l>>r;
  	l--;r--;
  	ll to;
  	if((l&1)==(r&1)) to=r;
  	else to=r-1;
  	ll diff1=differ[l];
  	bool val1=diff1>to;
  	if(to==r) to--;
  	else to++;
  	ll diff2=differ[l+1];
  	bool val2=diff2>to;
  	ll k=r-l+1;
  	ll ans=(k*(k+1))/2;
  	ans--;
  	k--;
  	bool val3=s[l]==s[l+1] && (l+1)<r;
  	ll temp=k;
  	if(temp&1) temp--;
  	ll hello=temp/2;
  	if(val3 && val1 && val2) ans-=(hello*(hello+1));
  	temp=k;
  	if((temp&1)==0) temp--;
  	ll z=(temp+1)/2;
  	if(val1 && val2){
  		ans-=z*z;
  		ans++;
  	}
  	if(isPalindrome(l,r)) ans-=(r-l+1);
  	cout<<ans<<endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
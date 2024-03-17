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
const int MAXN = 1e6+7;
const ll p=1000000007;
long long fac[MAXN + 1], inv[MAXN + 1];

ll binexp(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1) res*=a;
		res%=p;
		a*=a;
		a%=p;
		n>>=1;
	}
	return res;
}

void factorial(ll p)
{
    fac[0] = 1;
    for (ll i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}
 
/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p) time */
void inverses(ll p)
{
    inv[MAXN] = binexp(fac[MAXN], p - 2);
    for (ll i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % p;
    }
}

void solve(){
	string s;
    cin>>s;
    ll n=s.length();
    vector<ll>freq(26,0);
    for(char ch:s){
        freq[ch-'a']++;
    }
	ll ans=fac[n];
    for(ll k:freq){
        ans*=inv[k];
        ans%=mod;
    }
	cout<<ans<<endl;
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
    factorial(p);
    inverses(p);
    while (t--)
    {
        solve();
    }
    return 0;
}
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
 
void solve(){
  ll n,k,m;
  cin>>n>>k>>m;
  string s;
  cin>>s;
  ll segments=0,cnt=0;
  map<char,ll>mp;
  string ans="";
  for(ll i=0;i<m;i++){
  	mp[s[i]]++;
  	if(mp[s[i]]==1) cnt++;
  	if(cnt==k){
  		cnt=0;
  		segments++;
  		mp.clear();
  		ans+=s[i];
  	}
  }
  if(segments>=n) cout<<"YES\n";
  else{
  	char c;
  	for(char ch='a';ch<'a'+k;ch++){
  		if(mp[ch]==0){
  			c=ch;
  			break;
  		}
  	}
  	for(ll i=segments+1;i<=n;i++) ans+=c;
  	cout<<"NO\n";
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
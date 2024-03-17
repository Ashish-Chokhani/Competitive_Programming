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
  ll n;
  cin>>n;
  ll ones=__builtin_popcountll(n);
  ll p1=n,p2=n;
  if(ones&1) cout<<"second"<<endl;
  else cout<<"first"<<endl;
  cout.flush();
  ll cnt=0;
  bool isAlice=(ones&1)==0;
  auto calcLog=[&](ll a){
    ll LOG=0;
    while(a){
      LOG++;
      a>>=1;
    }
    return LOG-1;
  };
  while(1){
	if(!isAlice){
		cin>>p1>>p2;
	}
    else{
    	n=__builtin_popcountll(p1)&1?p2:p1;
	  	ll mst_bit=calcLog(n);
	  	p1=(1LL<<mst_bit);
	  	p2=n^p1;
  	    cout<<p1<<" "<<p2<<endl;
  	    cout.flush();
  	    cnt++;
  	    assert(cnt<=63);
  	}
  	if(p1==0 && p2==0) break;
  	isAlice=!isAlice;
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
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
  vector<ll>a(n),d(n);
  for(ll &x:a) cin>>x;
  for(ll &x:d) cin>>x;
  vector<ll>monsters(n);
  vector<ll>l(n),r(n);
  iota(monsters.begin(),monsters.end(),0LL);
  iota(l.begin(),l.end(),-1);
  iota(r.begin(),r.end(),1);
  set<ll>die;
  for(ll rounds=1;rounds<=n;rounds++){
  	set<ll>die;
  	for(ll &monster:monsters){
  		ll total_damage=0;
  		if(l[monster]!=-1) total_damage+=a[l[monster]];
  		if(r[monster]!=n) total_damage+=a[r[monster]];
  		if(total_damage>d[monster]) die.insert(monster);
  	}
  	monsters.clear();
  	for(ll x:die){
  		if(r[x]!=n){
  			l[r[x]]=l[x];
  			if(die.find(r[x])==die.end()) monsters.push_back(r[x]);
  		}
  		if(l[x]!=-1){
  			r[l[x]]=r[x];
  			if(die.find(l[x])==die.end()) monsters.push_back(l[x]);
  		}
  	}
  	cout<<(ll)die.size()<<" \n"[rounds==n];
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
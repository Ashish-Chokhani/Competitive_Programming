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
  ll n,m;
  cin>>n>>m;
  if(m>=n){
  	cout<<"-1\n";
  	return;
  }
  bool isSame=false,isDifferent=false,ok=true;
  ll cnt=0;
  vector<ll>b;
  for(ll bits=63;bits>=0;bits--){
  	ll bit_n=n>>bits&1;
  	ll bit_m=m>>bits&1;
  	if(!bit_n && bit_m && cnt<2){
  		cout<<"-1\n";
  		return;
  	}
  	if(bit_n && bit_n==bit_m){
  		isSame=true;
  		cnt++;
  	}
  	else if(bit_n && bit_n!=bit_m){
  		isDifferent=true; 
  		cnt++;
  		if(cnt==2 && !isSame) ok=false;
  		b.push_back(bits);
  	}
  }
  if(!ok){
  	cout<<"2\n";
  	ll temp=m|(1LL<<b[1]);
    cout<<n<<" "<<temp<<" "<<m<<endl;
  	return;
  }
  cout<<"1\n";
  cout<<n<<" "<<m<<endl;
} 

//6->110
//3->011
//1->001

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
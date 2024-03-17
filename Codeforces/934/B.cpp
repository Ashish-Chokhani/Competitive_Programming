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
  ll n,k;
  cin>>n>>k;
  vector<ll>arr(2*n);
  ll pos=0;
  vector<ll>first,second;
  map<ll,ll>first_freq,second_freq;
  for(auto &x:arr){
    cin>>x;
    if(pos<n){
    	first.push_back(x);
    	first_freq[x]++;
    }
    else{
    	second.push_back(x);
    	second_freq[x]++;
    }
    pos++;
  }
  k*=2;
  ll pushes=0;
  vector<ll>ans1,ans2;
  for(auto it:first_freq){
  	if(it.second==2 && pushes+2<=k){
  		ans1.push_back(it.first);
  		ans1.push_back(it.first);
  		pushes+=2;
  	}
  }
  ll pushes1=0;
  for(auto it:second_freq){
  	if(it.second==2 && pushes1+2<=pushes){
  		ans2.push_back(it.first);
  		ans2.push_back(it.first);
  		pushes1+=2;
  	}
  }
  assert(pushes1==pushes);
  
  for(auto it:first_freq){
  	if(it.second==1 && pushes<k){
  		ans1.push_back(it.first);
  		ans2.push_back(it.first);
  		pushes++;
  	}
  }
  for(auto it:ans1) cout<<it<<" ";
  cout<<endl;
  for(auto it:ans2) cout<<it<<" ";
  cout<<endl;
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
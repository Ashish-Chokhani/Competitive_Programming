#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long int ll;
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

ll maxVal=1e18;

void solve(){
  ll n,q;
  cin>>n>>q;
  vector<ll>arr;
  ll ind=0;
  map<ll,ll>what;
  while(n--){
  	ll type,x;
  	cin>>type>>x;
  	ll flag=(ind==0) || (arr.back()<maxVal);
  	if(!flag) continue;
  	if(type==1){
  		if(ind==0) arr.push_back(1);
  		else arr.push_back(arr.back()+1);
  		what[ind]=x;
  	}
  	else{
  		ll val;
  		if(arr.back()>maxVal/(x+1)) val=maxVal;
  		else val=arr.back()*(x+1);
  		val=min(val,maxVal);
	    arr.push_back(val);	
  	}
  	ind++;
  }
  auto istype1=[&](ll ind)->bool{
  	return what[ind]!=0;
  };
  auto nextVal=[&](ll curVal,ll ind)->ll{
  	ll prevVal=arr[ind-1];
  	if(curVal%prevVal==0) return prevVal;
  	return curVal%prevVal;
  };
  while(q--){
  	ll val;
  	cin>>val;
  	while(1){
  	   ll i=lower_bound(arr.begin(),arr.end(),val)-arr.begin();
  	   if(istype1(i)){
  	   	cout<<what[i]<<" \n"[q==0];
  	   	break;
  	   }
  	   val=nextVal(val,i);
  	}
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
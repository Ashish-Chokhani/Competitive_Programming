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
  string s;
  cin>>s;
  ll q;
  cin>>q;
  vector<pair<char,char>>queries;
  while(q--){ 
  	char a,b;
  	cin>>a>>b;
  	queries.push_back({a,b});
  }
  map<char,char>what;
  for(char ch='a';ch<='z';ch++){
  	char cur=ch,temp=ch;
  	for(pair<char,char>z:queries){
  		char x=z.first;
  		char y=z.second;
  		if(x==cur) cur=y;
  	}
  	what[temp]=cur;
  }
  for(ll i=0;i<n;i++){
  	s[i]=what[s[i]];
  }
  cout<<s<<endl;
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
    while (t--)
    {
        solve();
    }
    return 0;
}
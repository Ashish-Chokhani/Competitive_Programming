#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
template<class T>void print(T x)
{
  cerr << x;
}
template<class T, class V>
         void print(pair<T , V> x)
{
  print(x.first); 
  cerr << ':';
  print(x.second);
}
template<class T>
         void print(vector<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T,
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T, 
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(unordered_set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T, class V>
         void print(vector<pair<T, V>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x.first);
    cerr << ":"; 
    print(x.second);
    cerr << ' ';
  }
  cerr << ']';
}
template <class T, class V> 
          void print(map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T, class V> 
          void print(unordered_map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T> 
          void print(vector<vector<T>> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template<class T>
         void print(stack<T> &a)
{
  cerr << '[' << ' ';
  stack<T>temp=a;
  while(!temp.empty())
  {
    auto val=temp.top();
    temp.pop();
    print(val); 
    cerr << " ";
  }
  cerr << ']';
}

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
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll>a(n),d(m),f(k);
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<m;i++) cin>>d[i];
	for(ll i=0;i<k;i++) cin>>f[i];
	ll max_diff=0,second_max=0;
    ll prv,nxt;
    for(ll i=1;i<n;i++){
    	if(a[i]-a[i-1]>max_diff){
    		second_max=max_diff;
    		max_diff=a[i]-a[i-1];
    		prv=a[i-1];
    		nxt=a[i];
    	}
    	else second_max=max(second_max,a[i]-a[i-1]);
    }
    sort(d.begin(),d.end());
    sort(f.begin(),f.end());
    // debug(d);
    // debug(f);
    auto findGreaterEqual=[&](ll targ){
    	ll cur_diff=1e13;
    	for(ll i=0;i<m;i++){
    		ll val=targ-d[i];
    		ll ind=lower_bound(f.begin(),f.end(),val)-f.begin();
    		if(ind<k){
    			cur_diff=min(cur_diff,d[i]+f[ind]-targ);
    		}
    	}
    	return targ+cur_diff;
    };
    auto findSmaller=[&](ll targ){
    	ll cur_diff=1e13;
    	for(ll i=0;i<m;i++){
    		ll val=targ-d[i];
    		ll ind=lower_bound(f.begin(),f.end(),val)-f.begin();
    		ind--;
    		if(ind>=0 && ind<k){
    			cur_diff=min(cur_diff,targ-d[i]-f[ind]);
    		}
    	}
    	return targ-cur_diff;
    };
    // debug(prv);
    // debug(nxt);
    // Handle n==2 explicitly
    ll z1=(prv+nxt)/2;
    ll z2=(prv+nxt+1)/2;
    ll v1=findGreaterEqual(z1);
    ll v2=findGreaterEqual(z2);
    ll v3=findSmaller(z1);
    ll v4=findSmaller(z2);
    //cout<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
    ll val1=max_diff,val2=max_diff,val3=max_diff,val4=max_diff;
    if(v1>=prv && v1<=nxt) val1=max(v1,prv+nxt-v1)-prv;
    if(v2>=prv && v2<=nxt) val2=max(v2,prv+nxt-v2)-prv;
    if(v3>=prv && v3<=nxt) val3=max(v3,prv+nxt-v3)-prv;
    if(v4>=prv && v4<=nxt) val4=max(v4,prv+nxt-v4)-prv;
    //cout<<val1<<" "<<val2<<" "<<val3<<" "<<val4<<endl;
    ll c=min(val1,val3);
    ll e=min(val2,val4);
    cout<<max(second_max,min(c,e))<<endl;
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
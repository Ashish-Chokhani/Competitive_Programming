#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
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

const ll maxN=500;

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  map<ll,ll>block_element;
  bool isValidBlock[maxN];
  memset(isValidBlock,true,sizeof(isValidBlock));
  for(ll i=0;i<n;i+=maxN){
	for(ll j=0;j<maxN;j++){
		ll cur_idx=i+j;
		if(cur_idx>=n) continue;
		ll block_id=cur_idx/maxN;
		if(block_element[block_id]==0) block_element[block_id]=arr[cur_idx];
		else if(block_element[block_id]!=arr[cur_idx])isValidBlock[block_id]=false;
	}
  }
  
  auto findDifferenElement=[&](ll cur_id,ll till){
  	ll cur_idx=cur_id;
  	ll block_id=cur_idx/maxN;
  	ll cur=arr[cur_idx];
  	pair<ll,ll>ans={-1,-1};
  	if(cur_id==till) return ans;
  	while(cur_idx<=till){
  		if(arr[cur_idx]!=cur){
  			ans.first=cur_id+1;
  			ans.second=cur_idx+1;
  			break;
  		}
  		cur_idx++;
  	}
  	return ans;
  };
  
  ll q;
  cin>>q;
  
  while(q--){
  	ll l,r;
  	cin>>l>>r;
  	--l;--r;
  	ll block_id_l=l/maxN;
  	ll block_id_r=r/maxN;
  	pair<ll,ll>ans={-1,-1};
  	ans=findDifferenElement(l,min(r,((block_id_l+1)*maxN)-1));
  	if(ans.first==-1) ans=findDifferenElement(max(l,block_id_r*maxN),r);
  	if(ans.first==-1 && arr[l]!=arr[r]){
  		ans.first=l+1;
  		ans.second=r+1;
  	}
  	if(ans.first==-1){
  		for(ll id=block_id_l+1;id<block_id_r;id++){
	  		if(isValidBlock[id] && block_element[id]==arr[l]) continue;
	  		else if(!isValidBlock[id]){
	  			ans=findDifferenElement(max(l,id*maxN),min(r,((id+1)*maxN)-1));
	  			break;
	  		}
	  		else{
	  			if(arr[l]!=arr[id*maxN]){
	  			  ans.first=l+1;
	  			  ans.second=(id*maxN)+1;
	  			  break;	
	  			}
	  		}
  	    }
  	}
  	cout<<ans.first<<" "<<ans.second<<endl;
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
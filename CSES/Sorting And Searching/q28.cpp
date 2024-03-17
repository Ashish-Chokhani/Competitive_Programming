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


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

void balance(multiset<int>&mini,multiset<int>&maxi){
	ll left_size=maxi.size();
	ll right_size=mini.size();
	if(left_size-right_size==0 || left_size-right_size==1) return;
	if(left_size>right_size){
		int ele=*maxi.rbegin();
		maxi.erase(maxi.find(ele));
		mini.insert(ele);
		return;
	}
	int ele=*mini.begin();
	mini.erase(mini.find(ele));
	maxi.insert(ele);
	return;
}

void insert(int num,multiset<int>&mini,multiset<int>&maxi){
	ll left_size=maxi.size();
	if(left_size==0){
		maxi.insert(num);
		return;
	}
	if(num>*maxi.rbegin()) mini.insert(num);
	else maxi.insert(num);
	balance(mini,maxi);
}

void deleteNum(int num,multiset<int>&mini,multiset<int>&maxi){
	if(num>*maxi.rbegin()){
		auto it=mini.find(num);
		mini.erase(it);
	}
	else{
		auto it=maxi.find(num);
		maxi.erase(it);
	}
	balance(mini,maxi);
}

int findMedian(multiset<int>&mini,multiset<int>&maxi){
	return *maxi.rbegin();
}

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  multiset<int>mini,maxi;
  for(ll i=0;i<k;i++){
  	insert(arr[i],mini,maxi);
  }
  ll val=findMedian(mini,maxi);
  cout<<val<<" ";
  for(ll i=k;i<n;i++){
  	deleteNum(arr[i-k],mini,maxi);
  	insert(arr[i],mini,maxi);
  	cout<<findMedian(mini,maxi)<<" ";
  }
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
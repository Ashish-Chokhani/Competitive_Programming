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

ll left_sum=0,right_sum=0;

void balance(multiset<int>&mini,multiset<int>&maxi){
	ll left_size=maxi.size();
	ll right_size=mini.size();
	if(left_size-right_size==0 || left_size-right_size==1) return;
	if(left_size>right_size){
		int ele=*maxi.rbegin();
		maxi.erase(maxi.find(ele));
    left_sum-=ele;
		mini.insert(ele);
    right_sum+=ele;
		return;
	}
	int ele=*mini.begin();
	mini.erase(mini.find(ele));
  right_sum-=ele;
	maxi.insert(ele);
  left_sum+=ele;
	return;
}

void insert(int num,multiset<int>&mini,multiset<int>&maxi){
	ll left_size=maxi.size();
	if(left_size==0){
		maxi.insert(num);
    left_sum+=num;
		return;
	}
	if(num>*maxi.rbegin()){
    mini.insert(num);
    right_sum+=num;
  }
	else{
    maxi.insert(num);
    left_sum+=num;
  }
	balance(mini,maxi);
}

void deleteNum(int num,multiset<int>&mini,multiset<int>&maxi){
	if(num>*maxi.rbegin()){
		auto it=mini.find(num);
		mini.erase(it);
    right_sum-=num;
	}
	else{
		auto it=maxi.find(num);
		maxi.erase(it);
    left_sum-=num;
	}
	balance(mini,maxi);
}

int findMedian(multiset<int>&mini,multiset<int>&maxi){
	return *maxi.rbegin();
}

ll findRangeSum(ll l,ll r,vector<ll>&pre){
  if(l==0) return pre[r];
  return pre[r]-pre[l-1];
}

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>arr(n);
  vector<ll>pre(n,0);
  for(auto &x:arr){
    cin>>x;
  }
  pre[0]=arr[0];
  for(ll i=1;i<n;i++){
    pre[i]=arr[i]+pre[i-1];
  }
  multiset<int>mini,maxi;
  for(ll i=0;i<k;i++){
  	insert(arr[i],mini,maxi);
  }
  ll val=findMedian(mini,maxi);
  ll requiredSum_left=val*maxi.size();
  ll curSum_left=left_sum;
  ll requiredSum_right=val*mini.size();
  ll curSum_right=right_sum;
  cout<<abs(curSum_left-requiredSum_left)+abs(curSum_right-requiredSum_right)<<" ";
  for(ll i=k;i<n;i++){
  	deleteNum(arr[i-k],mini,maxi);
  	insert(arr[i],mini,maxi);
  	val=findMedian(mini,maxi);
    requiredSum_left=val*maxi.size();
    curSum_left=left_sum;
    requiredSum_right=val*mini.size();
    curSum_right=right_sum;
    cout<<abs(curSum_left-requiredSum_left)+abs(curSum_right-requiredSum_right)<<" ";
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
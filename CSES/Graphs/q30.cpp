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
// for erase use: st.erase(st.find_by_order(val);

void generateSubstrings(ll n,vector<char>&substring,vector<string>&substrings){
	if(n==0){
		string temp="";
		for(char &ch:substring) temp+=ch;
		substrings.push_back(temp);
	    return;
	}
	substring.push_back('0');
	generateSubstrings(n-1,substring,substrings);
	substring.pop_back();
	substring.push_back('1');
	generateSubstrings(n-1,substring,substrings);
	substring.pop_back();
}

void solve(){
  ll n;
  cin>>n;
  if(n==1){
  	cout<<"01\n";
  	return;
  }
  vector<char>substring;
  vector<string>substrings;
  generateSubstrings(n-1,substring,substrings);
  map<string,set<pair<string,string>>>adj;
  map<string,ll>outdegree;
  for(auto &s:substrings){
  	//debug(s);
  	string t=s.substr(1,n-2);
  	string s1=t+'0';
  	string s2=t+'1';
  	adj[s].insert({"1",s2});
  	adj[s].insert({"0",s1});
  	outdegree[s]+=2;
  }
  stack<pair<string,string>>st;
  
  st.push({"2",substrings[0]});
  string ans="";
  while(!st.empty()){
  	auto it=st.top();
  	string ch=it.first;
  	string node=it.second;
  	// debug(node);
  	// debug(ch);
  	if(outdegree[node]==0){
  		ans+=ch;
  		st.pop();
  	}
  	else{
  		auto to=adj[node].begin();
  		auto val=*to;
  		string to_node=val.second;
  		string to_ch=val.first;
  		adj[node].erase(to);
  		outdegree[node]--;
  		st.push({to_ch,to_node});
  	}
  }
  string temp=ans.substr(0,(ll)ans.length()-1);
  cout<<temp+substrings[0]<<endl;
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
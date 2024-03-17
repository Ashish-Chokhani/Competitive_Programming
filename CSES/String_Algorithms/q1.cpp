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

struct Node{
	bool flag;
	Node*links[26];
	Node(){
		flag=false;
		for(ll i=0;i<26;i++){
			links[i]=NULL;
		}
	}
};

Node* head=new Node();

Node* next(Node* node,char ch){
	return node->links[ch-'a'];
}

bool hasNext(Node* node,char ch){
	return node->links[ch-'a']!=NULL;
}

bool isEnd(Node* node){
	return node->flag;
}

void setEnd(Node* node){
	node->flag=true;
}

void insert(string &s){
	Node*cur=head;
	for(char ch:s){
		if(!hasNext(cur,ch)){
			cur->links[ch-'a']=new Node();
		}
		cur=next(cur,ch);
	}
	setEnd(cur);
}

void solve(){
	string s;
	cin>>s;
	ll k;
	cin>>k;
	while(k--){
		string t;
		cin>>t;
		insert(t);
	}
	ll n=s.length();
	ll dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[n]=1;
	for(ll i=n-1;i>=0;i--){
		Node* pos=head;
		for(ll j=i;j<n;j++){
			if(!pos->links[s[j]-'a']) break;
			pos=next(pos,s[j]);
			if(isEnd(pos)) dp[i]+=dp[j+1];
			dp[i]%=mod;
		}
	}
	cout<<dp[0]<<endl;
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
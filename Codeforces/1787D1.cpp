#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define endl '\n'
#define ilihg ios_base::sync_with_stdio(false);cin.tie(NULL)
 
void dfs(int i,vector<int> &b,vector<int> v[]){
	b[i]=1;
	for(auto u:v[i]){
		if(!b[u]){
			dfs(u,b,v);
		}
	}
}
int dfs1(int i,vector<int> &b,vector<int> v[],vector<ll> &g){
	b[i]=1;
	g[i]=1;
	for(auto u:v[i]){
		if(!b[u]){
			g[i]+=dfs1(u,b,v,g);
		}
	}
	return g[i];
}
int main(){
	int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int a[n];
    	vector<int> v[n+1],w[n+1];
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    		if(i+a[i]>=n||i+a[i]<0){
    			v[i].push_back(n);
    			w[n].push_back(i);
    		}
    		else{
    			v[i].push_back(i+a[i]);
    			w[i+a[i]].push_back(i);
    		}
    	}
    	vector<int> b(n+1);
    	vector<ll> g(n+1);
    	dfs1(n,b,w,g);
    	if(b[0]==0){
    		vector<int> c(n+1);
    		ll x=0;
    		for(int i=0;i<n;i++){
    			if(b[i]){
    				x++;
    			}
    		}
    		dfs(0,c,v);
    		ll ans=0;
    		for(int i=0;i<n;i++){
    			if(c[i]){
    				ans+=x+1+n;
    			}
    		}
    		cout<<ans<<endl;
    	}
    	else{
    		vector<int> c(n+1);
    		ll x=0;
    		for(int i=0;i<n;i++){
    			if(b[i]){
    				x++;
    			}
    		}
            cout<<x<<"\n";
    		dfs(0,c,v);
    		ll ans=0;
    		for(int i=0;i<n;i++){
                cout<<i<<" "<<g[i]<<"\n";
    			if(c[i]){
    				ans+=x-g[i]+n+1;
    			}
    			else{
    				ans+=2*n+1;
    			}
    		}
    		cout<<ans<<endl;
    	}
	}  
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const ll mod = 1000000007; //998244353
// const ll INF = 1e18;
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

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define TOP_LEFT 4
#define BOTTOM_LEFT 5
#define TOP_RIGHT 6
#define BOTTOM_RIGHT 7

string s;
vector<vector<bool>>vis(7,vector<bool>(7,false));
ll dx[8]={-1,0,1,0,-1,1,-1,1};
ll dy[8]={0,-1,0,1,-1,-1,1,1};

bool isValid(ll x,ll y){
	return x>=0 && y>=0 && x<=6 && y<=6;
}

bool isInValidVisit(ll x,ll y){
	vector<bool>visited(4,false);
	for(ll dir=0;dir<4;dir++){
		ll newX=x+dx[dir];
		ll newY=y+dy[dir];
		if(!isValid(newX,newY)) visited[dir]=1;
		else visited[dir]=vis[newX][newY];
	}
	if(visited[LEFT] && visited[RIGHT] && !visited[UP] && !visited[DOWN]) return true;
	if(visited[UP] && visited[DOWN] && !visited[LEFT] && !visited[RIGHT]) return true;
	if(isValid(x-1,y-1) && vis[x-1][y-1] && !visited[UP] && !visited[LEFT]) return true;
	if(isValid(x+1,y-1) && vis[x+1][y-1] && !visited[LEFT] && !visited[DOWN]) return true;
	if(isValid(x-1,y+1) && vis[x-1][y+1] && !visited[RIGHT] && !visited[UP]) return true;
	if(isValid(x+1,y+1) && vis[x+1][y+1] && !visited[DOWN] && !visited[RIGHT]) return true;
	return false;
}

ll fun(ll x,ll y,ll pos){
	if(pos==48) return x==6 && y==0;
	if(x==6 && y==0) return 0;
	if(vis[x][y]) return 0;
	if(isInValidVisit(x,y)) return 0;
	vis[x][y]=1;
	ll ans=0;
	if(s[pos]=='?'){
		for(ll dir=0;dir<4;dir++){
			ll newX=x+dx[dir];
			ll newY=y+dy[dir];
			if(!isValid(newX,newY) || vis[newX][newY]) continue;
			ans+=fun(newX,newY,pos+1);
	    }
	}
	else if(s[pos]=='R' && y<=5){
		ans+=fun(x,y+1,pos+1);
	}
	else if(s[pos]=='L' && y>=1){
		ans+=fun(x,y-1,pos+1);
	}
	else if(s[pos]=='U' && x>=1){
		ans+=fun(x-1,y,pos+1);
	}
	else if(s[pos]=='D' && x<=5){
		ans+=fun(x+1,y,pos+1);
	}
	vis[x][y]=0;
	return ans;
}

void solve(){
	cin>>s;
	cout<<fun(0,0,0)<<endl;
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
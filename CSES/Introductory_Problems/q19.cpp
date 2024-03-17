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

bool isValid(ll i,ll j,vector<vector<int>>&vis){
	return i>=0 && j>=0 && i<7 && j<7 && !vis[i][j];
}

char findPos(ll dir){
	if(dir==0) return 'U';
	else if(dir==1) return 'L';
	else if(dir==2) return 'R';
	return 'D';
}


void cntWays(ll ind,ll i,ll j,string &s,vector<vector<int>>&vis,vector<string>&paths){
	if(ind==48){
		if(i==6 && j==0){
			paths.push_back(s);
		}
		return;
	}
	if(i==6 && j==0){
		if(ind==48){
			paths.push_back(s);
		}
		return;
	}
	
	bool hitUpWall= i==0 && j>=1 && j<=5 && vis[i+1][j] && !vis[i][j-1] && !vis[i][j+1]; 
	bool hitDownWall= i==6 && j>=1 && j<=5 && vis[i-1][j] && !vis[i][j-1] && !vis[i][j+1]; 
	bool hitLeftWall= j==0 && i>=1 && i<=5 && vis[i][j+1] && !vis[i-1][j] && !vis[i+1][j]; 
	bool hitRightWall= j==6 && i>=1 && i<=5 && vis[i][j-1] && !vis[i-1][j] && !vis[i+1][j];
	
	bool hitUpMove= i<=5 && i>=1 && j>=1 && j<=5 && vis[i+1][j] && vis[i-1][j] && !vis[i][j-1] && !vis[i][j+1]; 
	bool hitLeftMove= j<=5 && j>=1 && i>=1 && i<=5 && vis[i][j+1] && vis[i][j-1] && !vis[i-1][j] && !vis[i+1][j]; 
	
	if(hitUpWall || hitDownWall || hitLeftWall || hitRightWall || 
		hitUpMove || hitLeftMove) return; 
	
	ll dx[]={-1,0,0,1};
	ll dy[]={0,-1,1,0};
    vis[i][j]=1;
	for(ll dir=0;dir<4;dir++){
		ll newX=i+dx[dir];
		ll newY=j+dy[dir];
		if(isValid(newX,newY,vis)){
			string temp=s;
			temp+=findPos(dir);
			cntWays(ind+1,newX,newY,temp,vis,paths);
		}
	}
	vis[i][j]=0;
	return;
}

void solve(){
	string s;
	cin>>s;
	vector<vector<int>>vis(7,vector<int>(7,0));
	vector<string> paths;
	string temp="";
	cntWays(0,0,0,temp,vis,paths);
	int ans=0;
	// for(string &path:paths){
	// 	int flag=1;
	// 	for(int i=0;i<48;i++){
	// 		if(s[i]!='?' && s[i]!=path[i]) flag=0;
	// 	}
	// 	ans+=flag;
	// }
	cout<<ans<<"\n";
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
    
    #ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
	
    return 0;
}
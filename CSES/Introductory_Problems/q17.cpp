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

bool isPossibleToPlace(vector<string>&grid,ll n,ll m){
	if(grid[n][m]=='#' || grid[n][m]=='*') return false;
	//Left Diagonal upwards
	ll i,j;
	i=n-1,j=m-1;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		i--; j--;
	}
	
	//Left Diagonal downwards
	i=n+1,j=m+1;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		i++; j++;
	}
	
	//Right Diagonal downwards
	i=n-1,j=m+1;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		i--; j++;
	}
	
	//Right Diagonal downwards
	i=n+1,j=m-1;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		i++; j--;
	}
	
	//Upwards
	i=n-1,j=m;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		i--;
	}
	
	//Downwards
	i=n+1,j=m;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		i++;
	}
	
	//Leftwards
	i=n,j=m-1;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		j--;
	}
	
	//Downwards
	i=n,j=m+1;
	while(i>=0 && j>=0 && i<8 && j<8){
		if(grid[i][j]=='#') return false;
		j++;
	}
	return true;
}

void findWaystoPlace(ll remQueens,vector<string>&grid,ll row,ll &ans){
	if(row==8){
		ans+=(remQueens==0);
		return;
	}
	for(int col=0;col<8;col++){
		if(isPossibleToPlace(grid,row,col)){
		grid[row][col]='#';
		findWaystoPlace(remQueens-1,grid,row+1,ans);
		grid[row][col]='.';
		}
	}
}

void solve(){
	vector<string>grid(8);
	for(string &s:grid){
		cin>>s;
	}
	ll ans=0;
	findWaystoPlace(8,grid,0,ans);
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
    return 0;
}
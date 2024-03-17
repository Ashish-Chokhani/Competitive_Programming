#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(ll i,ll j,ll dir,vector<vector<char>>&arr,vector<vector<vector<ll>>>&vis,ll n,ll m){
    return i>=0 && j>=0 && i<n && j<m && !vis[i][j][dir] && arr[i][j]!='#';
}

void BFS(vector<vector<char>>&arr,vector<vector<vector<ll>>>&vis,ll n,ll m){
    queue<pair<pair<ll,ll>,ll>>q;
    vis[1][1][4]=1;
    q.push({{1,1},4});
    ll dx[]={0,0,-1,1};
    ll dy[]={-1,1,0,0};
    while(!q.empty()){
        ll i=q.front().first.first;
        ll j=q.front().first.second;
        ll cur_dir=q.front().second;
        //cout<<i<<" "<<j<<" "<<cur_dir<<"\n";
        q.pop();
        if(cur_dir==4){
            for(ll dir=0;dir<4;dir++){
                ll newX=i+dx[dir];
                ll newY=j+dy[dir];
                if(isValid(newX,newY,dir,arr,vis,n,m)){
                    q.push({{newX,newY},dir});
                    vis[newX][newY][dir]=1;
                }
            }
        }
        else
        {
            ll newX=i+dx[cur_dir];
            ll newY=j+dy[cur_dir];
            if(isValid(newX,newY,cur_dir,arr,vis,n,m)){
                q.push({{newX,newY},cur_dir});
                vis[newX][newY][cur_dir]=1;
            }
            else{
                q.push({{i,j},4});
                vis[i][j][4]=1;
            }
        }
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<vector<ll>>>vis(n,vector<vector<ll>>(m,vector<ll>(5,0)));
    BFS(arr,vis,n,m);
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll cnt=0;
            for(ll dir=0;dir<5;dir++){
                cnt|=vis[i][j][dir];
            }
            ans+=cnt;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}
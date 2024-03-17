#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char nextChar(char ch){
    if(ch=='s') return 'n';
    if(ch=='n') return 'u';
    if(ch=='u') return 'k';
    if(ch=='k') return 'e';
    if(ch=='e') return 's';
    return 'A';
}

bool fun(ll i,ll j,char ch,vector<vector<char>>&arr,ll n,ll m,vector<vector<ll>>&vis){
     vis[i][j]=1;

    if(i==n-1 && j==m-1)
    return true;

    ll dx[]={-1,0,0,1};
    ll dy[]={0,1,-1,0};
    char next=nextChar(ch);
    bool flag=false;
    for(ll dir=0;dir<4;dir++){
        ll newRow=i+dy[dir];
        ll newCol=j+dx[dir];
        if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && arr[newRow][newCol]==next && !vis[newRow][newCol])
        flag = flag | fun(newRow,newCol,next,arr,n,m,vis);
    }
    return flag;
}

void solve()
{
    ll n,m;
    cin>>n >>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    string word="snuke";
    if(arr[0][0]!='s'){
        cout<<"No\n";
        return;
    }
    vector<vector<ll>>vis(n+1,vector<ll>(m+1,0));
    if(fun(0,0,'s',arr,n,m,vis)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

int main()
{
    solve();
    return 0;
}
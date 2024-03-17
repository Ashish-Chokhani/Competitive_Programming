#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll i,ll j,int n,int m,vector<pair<ll,ll>>&ans,map<int,vector<int>>&where_in_row,map<int,vector<int>>&where_in_col){
    ans.push_back({i,j});
    where_in_row[i].erase(j);
    vector<int>tmp_row=where_in_row[i];
    for(int col:tmp_row){
        // where_in_row[i].clear();
        //where_in_col[col][i].clear();
        DFS(i,col,n,m,ans,where_in_row,where_in_col);
    }
    // vector<int>tmp_col=where_in_col[j];
    // for(int row:tmp_col){
    //     where_in_col[row].clear();
    //     //where_in_col[j][row].clear();
    //     DFS(row,j,n,m,ans,where_in_row,where_in_col);
    // }
}

void solve(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<pair<ll,ll>>ans;
    map<int,vector<int>>where_in_row,where_in_col;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            where_in_row[i].push_back(j);
        }
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            where_in_col[j].push_back(i);
        }
    }
    DFS(a-1,b-1,n,m,ans,where_in_row,where_in_col);
    for(auto it:ans){
        cout<<it.first+1<<" "<<it.second+1<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(vector<vector<char>>&arr,ll n,ll m){
    for(ll i=0;i<n;i++){
        if(arr[i][m]!='o')
        return false;
    }
    return true;
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
    ll ans=0;
    for(ll j=0;j<m;j++){
        ll temp=j;
        while(temp<m && isValid(arr,n,temp)){
            temp++;
        }
        ans=max(ans,temp-j);
    }
    cout<<ans<<"\n";

}

int main()
{
    solve();
    return 0;
}
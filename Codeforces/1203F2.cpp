#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll i,ll r,vector<pair<ll,ll>>&arr){
    if(i<0 || r<1) return 0;

    ll pick=0,not_pick=0;
    if(arr[i].first<=r) pick=1+fun(i-1,r+arr[i].second,arr);

    not_pick=fun(i-1,r,arr);
    return max(pick,not_pick);
}

void solve(){
    ll n,r;
    cin>>n>>r;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    cout<<fun(n-1,r,arr)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

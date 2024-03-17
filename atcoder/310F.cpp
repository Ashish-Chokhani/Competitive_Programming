#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll i,ll mask,vector<ll>&arr){
    if(i<0) return (mask>>10)&1;

    ll val=0,newMask=mask;
    for(ll j=0;j<=10;j++){
        if(mask>>j){
            for(ll k=1;k<=max(10LL,arr[i]);k++){
                if(j+k>10) continue;
                newMask=newMask | (1LL<<(j+k));
            }
        }
    }
    if(arr[i]>10) val=(arr[i]-10) + fun(i-1,mask,arr);
    return val;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<fun(n-1,1,arr)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
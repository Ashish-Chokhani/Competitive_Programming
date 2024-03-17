#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

__int128 sum(ll w,vector<ll>&arr){
    ll n=arr.size();
    __int128 s=0;
    for(ll i=0;i<n;i++){
        s+=(arr[i]+(2*w))*(arr[i]+(2*w));
    }
    return s;
}

void solve(){
    ll n,c;
    cin>>n>>c;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll l=1,r=1e9+2;
    while(l<=r){
        ll mid=(l+r)/2;
        __int128 s=sum(mid,arr);
        if(s==c){
            cout<<mid<<"\n";
            return;
        }
        else if(s<c){
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
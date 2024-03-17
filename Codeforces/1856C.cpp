#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll val,ll k,vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        ll s=0,req=val;
        for(ll j=i;j<n;j++){
            if(arr[j]>=req) break;
            if(j==n-1) s+=1e9;
            s+=req-arr[j];
            req--;
        }
        if(s<=k) return true;
    }
    return false;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll l=1,r=1e9,ans;
    while(l<=r){
        ll mid=(l+r)/2;
        if(isPossible(mid,k,arr)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
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
    return 0;
}

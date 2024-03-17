#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findCoins(vector<ll>&arr,ll add,ll sub,ll val){
    ll ans=0;
    for(ll i=0;i<arr.size();i++){
        if(arr[i]==val) continue;
        if(arr[i]<val) ans+=(val-arr[i])*add;
        else ans+=(arr[i]-val)*sub;
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll mini=1e9+7,maxi=-1;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    ll add,sub;
    cin>>add>>sub;
    ll l=mini,r=maxi;
    ll ans=1e10;
    while(l<=r){
        ll m1=l+(r-l)/3;
        ll m2=r-(r-l)/3;
        ll v1=findCoins(arr,add,sub,m1);
        ll v2=findCoins(arr,add,sub,m2);
        ans=min(ans,min(v1,v2));
        if(v1<v2){
            r=m2-1;
        }
        else if(v1>v2){
            l=m1+1;
        }
        else{
            l=m1+1;
            r=m2-1;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

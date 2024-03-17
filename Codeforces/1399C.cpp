#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    ll ans=0;
    for(ll w=1;w<=100;w++){
        ll l=1,r=w-l,val=0;
        while(l<=r){
            if(l!=r)
            val+=min(mp[l],mp[r]);
            else 
            val+=mp[l]/2;
            l++;
            r--;
        }    
        ans=max(ans,val);
    }
    cout<<ans<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
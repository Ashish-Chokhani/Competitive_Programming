#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(vector<ll>&arr,ll n,ll h,ll x){
    ll val=0;
    for(ll i=0;i<n;i++){
        val+=max(0LL,h-arr[i]);
    }
    return val<=x;
}

void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    ll max_h=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        max_h=max(arr[i],max_h);
    }
    ll l=1,r=1e12,ans=1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(isPossible(arr,n,mid,x)){
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
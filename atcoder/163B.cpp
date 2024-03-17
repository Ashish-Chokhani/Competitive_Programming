#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin >> n >>m;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin()+2,arr.end());
    ll l=2,r=1+m;
    ll ans=1e17;
    while(r<n){
        ll v1=max(0LL,arr[0]-arr[l]);
        ll v2=max(0LL,arr[r]-arr[1]);
        ll v=v1+v2;
        ans=min(ans,v);
        l++;
        r++;
    }
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}
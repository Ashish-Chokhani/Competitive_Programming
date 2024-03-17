#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    vector<ll>where(n+1);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        where[arr[i]]=i;
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    ll L=(n+1)/2;
    ll R=(n+2)/2;
    ll ans=(n+1)/2;
    while(L>=1 && R<=n && ((L==R) || where[L]<where[L+1] && where[R-1]<where[R])){
        L--;
        R++;
        ans--;
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
    ll cnt=0;
    while(t--){
        solve();
    }
}
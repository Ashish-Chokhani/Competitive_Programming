#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    ll min_a=1e9+7,min_b=1e9+7;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        min_a=min(min_a,a[i]);
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        min_b=min(min_b,b[i]);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll op1=a[i]-min_a;
        ll op2=b[i]-min_b;
        ans+=op1+op2-min(op1,op2);
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
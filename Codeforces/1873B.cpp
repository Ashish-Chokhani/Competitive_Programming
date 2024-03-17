#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll prod=1;
    ll cnt0=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=0) prod*=arr[i];
        if(arr[i]==0) cnt0++;
    }
    if(cnt0>=2){
        cout<<"0\n";
        return;
    }
    if(cnt0==1){
        cout<<prod<<"\n";
        return;
    }
    ll val=prod;
    for(ll i=0;i<n;i++){
        val=max(val,(prod/arr[i])*(arr[i]+1));
    }
    cout<<val<<"\n";
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
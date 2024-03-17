#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll cntPos=0,cntNeg=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        cntPos+=arr[i]==1;
        cntNeg+=arr[i]==-1;
    }
    ll val=cntNeg%2!=0;
    ll val1=(cntNeg-cntPos+1)/2;
    if(cntPos>=cntNeg) cout<<val<<"\n";
    else cout<<val1+(val1%2 != cntNeg%2)<<"\n";
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
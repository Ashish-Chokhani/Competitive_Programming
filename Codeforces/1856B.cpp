#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    ll cntOnes=0;
    vector<ll>arr(n);
    ll s=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        cntOnes+=arr[i]==1;
        s+=arr[i];
    }
    if(n<2){
        cout<<"NO\n";
        return;
    }
    ll req=cntOnes*2 + (n-cntOnes);
    if(s>=req) cout<<"YES\n";
    else cout<<"NO\n";
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

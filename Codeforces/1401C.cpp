#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll mini=1e9+7;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mini=min(mini,arr[i]);
    }
    vector<ll>temp=arr;
    sort(temp.begin(),temp.end());
    ll flag=true;
    for(ll i=0;i<n;i++){
        if(temp[i]!=arr[i]){
            if(arr[i]%mini!=0){
                flag=false;
                //cout<<i<<" "<<arr[i]<<" "<<temp[i]<<" "<<__gcd(arr[i],temp[i]);
                break;
            }
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
        solve();
    }
    return 0;
}
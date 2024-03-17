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
    for(ll num=1;num<=n;num++){
        ll val=0;
        for(ll fact=1;fact*fact<=num;fact++){
            if(num%fact==0){
                val+=mp[fact];
                if(num/fact!=fact) val+=mp[num/fact];
            }
        }
        ans=max(ans,val);
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
    while(t--){
        solve();
    }
}
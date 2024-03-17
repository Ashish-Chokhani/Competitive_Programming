#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans=1e9;
    if(k!=4){
        for(auto x:arr){
            ll val=x%k;
            if(val==0) ans=0;
            ans=min(ans,k-val);
        }
    }
    else{
        for(auto x:arr){
            ll val=x%k;
            if(val==0) ans=0;
            ans=min(ans,k-val);
        }
        if(n>=2){
            ll cnt=0;
            for(auto x:arr){
                cnt+= (x&1) == 0 ;
            }
            ans=min(ans,max(0LL,2-cnt));
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
    cin>>t;
    while(t--)
    solve();
}
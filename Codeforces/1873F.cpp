#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>arr(n),h(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    for(ll i=0;i<n;i++){
        cin>>h[i];
    }
    vector<ll>suf(n+1);
    suf[n-1]=n-1;
    for(ll i=n-2;i>=0;i--){
        if(h[i]%h[i+1]==0){
            suf[i]=suf[i+1];
        }
        else{
            suf[i]=i;
        }
    }
    vector<pair<ll,ll>>range;
    ll ans=0;
    ll cur=0;
    while(cur<n){
        range.push_back({cur,suf[cur]});
        cur=suf[cur]+1;
    }
    for(auto it:range){
        ll i=it.first;
        ll j=it.second;
        ll s=0, cnt=0;
        ll low=i,high=i;
        while(high<=j && low<=high){
            s+=arr[high];
            if(s<=x){
                ans=max(ans,high-low+1);
                high++;
            }
            else{
                while(low<high && s>x){
                    s-=arr[low];
                    low++;
                }
                if(s<=x) ans=max(ans,high-low+1);
                high++;
            }
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
    ll cnt=0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
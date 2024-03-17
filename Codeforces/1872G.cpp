#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll range_sum(ll l,ll r,vector<ll>&pre){
    if(l==0) return pre[r];
    return pre[r]-pre[l-1];
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    vector<ll>non_zero;
    vector<ll>pre(n+1,0);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=1) non_zero.push_back(i);
        if(i==0) pre[i]=arr[i];
        else pre[i]=arr[i]+pre[i-1];
    }
    if(non_zero.size()>20){
        cout<<non_zero[0]+1<<" "<<non_zero.back()+1<<"\n";
        return;
    }
    ll prod=1;
    for(auto it:non_zero){
        prod*=arr[it];
        if(prod>1e6){
            cout<<non_zero[0]+1<<" "<<non_zero.back()+1<<"\n";
            return;
        }
    }
    ll ans_l=0,ans_r=0,sz=(ll)non_zero.size(),diff=0;
    for(ll l=0;l<sz;l++){
        prod=1;
        for(ll r=l;r<sz;r++){
            prod*=arr[non_zero[r]];
            ll val=prod-range_sum(non_zero[l],non_zero[r],pre);
            if(val>diff){
                diff=val;
                ans_l=non_zero[l];
                ans_r=non_zero[r];
            }
        }
    }
    cout<<ans_l+1<<" "<<ans_r+1<<"\n";
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
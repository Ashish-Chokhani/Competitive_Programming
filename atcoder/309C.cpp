#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end());
    vector<ll>pre(n);
    pre[0]=arr[0].second;
    for(ll i=1;i<n;i++){
        pre[i]=arr[i].second+pre[i-1];
    }
    for(ll i=0;i<n;i++){
        ll val=pre[n-1];
        if(i>=1)
        val-=pre[i-1];
        if(val<=k){
            if(i==0){
                cout<<"1\n";
                return;
            }
            else{
                cout<<arr[i-1].first+1<<"\n";
                return;
            }
        }
    }
    cout<<arr[n-1].first+1<<"\n";
}

int main()
{
    solve();
    return 0;
}
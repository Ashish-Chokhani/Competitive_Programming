#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kBitXNOR(ll a,ll b,ll k){
    ll res=0;
    for(ll i=0;i<k;i++){
        ll bit1=a&1;
        ll bit2=b&1;
        a>>=1;
        b>>=1;
        if(bit1==bit2){
            res=res | (1<<i);
        }
    }
    return res;
}

ll kBitNOR(ll a,ll b,ll k){
    ll res=0;
    for(ll i=0;i<k;i++){
        ll bit1=a&1;
        ll bit2=b&1;
        a>>=1;
        b>>=1;
        if(bit1!=1 || bit2!=1){
            res=res | (1<<i);
        }
    }
    return res;
}


void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        ll z;
        cin>>z;
        arr[i]={z,i};
    }
    sort(arr.begin(),arr.end());
    ll y=0;
    pair<ll,ll>ind;
    ll a_i=0,a_j=0;
    for(ll i=0;i<n-1;i++){
        ll val=kBitXNOR(arr[i].first,arr[i+1].first,k);
        if(val>=y)
        {
            y=val;
            a_i=arr[i].first;
            a_j=arr[i+1].first;
            ind.first=arr[i].second;
            ind.second=arr[i+1].second;
        }
    }
    ll x=kBitNOR(a_i,a_j,k);
    cout<<ind.first+1<<" "<<ind.second+1<<" "<<x<<"\n";
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
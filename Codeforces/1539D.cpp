#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compareInterval(pair<ll,ll>&x,pair<ll,ll>&y){
    return x.second>y.second;
}

void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),compareInterval);
    ll i=0,j=n-1,cntProducts=0,ans=0;
    while(i<=j){
        if(cntProducts>=arr[j].second){
            ans+=arr[j].first;
            cntProducts+=arr[j].first;
            j--;
        }
        else{
            ll req=arr[j].second-cntProducts;
            if(arr[i].first<=req){
                ans+=2*arr[i].first;
                cntProducts+=arr[i].first;
                i++;
            }
            else{
                ans+=2*req;
                cntProducts+=req;
                arr[i].first-=req;
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
    solve();
}
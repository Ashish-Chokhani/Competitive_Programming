#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    multiset<ll>st;
    for(ll i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]>x){
            st.insert(arr[i+1]-arr[i]);
        }
    }
    ll ans=st.size()+1;
    while(!st.empty() && k>0){
        auto it=st.begin();
        ll val=*it;
        st.erase(it);
        ll req=(val-1)/x;
        if(k<req) break;
        k-=req;
        ans--;
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
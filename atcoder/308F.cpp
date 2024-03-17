#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    multiset<ll>st;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        st.insert(x);
        ans+=x;
    }
    vector<ll>L(m),D(m);
    for(ll i=0;i<m;i++){
        cin>>L[i];
    }
    for(ll i=0;i<m;i++){
        cin>>D[i];
    }
    vector<pair<ll,ll>>arr(m);
    for(ll i=0;i<m;i++){
        arr[i]={D[i],L[i]};
    }
    sort(arr.rbegin(),arr.rend());
    for(auto it:arr){
        ll discount=it.first;
        ll leastPrice=it.second;
        auto it1=st.lower_bound(leastPrice);
        if(it1!=st.end()){
            ans-=discount;
            st.erase(it1);
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}
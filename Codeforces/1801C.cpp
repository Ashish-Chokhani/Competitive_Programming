#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr.begin(),arr.end());
    vector<ll>suf(n+1);
    suf[n]=-1e12;
    ll maxi=-1;
    for(ll i=n-1;i>=0;i--)
    {
        maxi=max(maxi,arr[i].second);
        suf[i]=maxi;
    }
    set<ll>st;
    ll ans=1e10;
    for(ll i=0;i<n;i++)
    {
        ans=min(ans,abs(arr[i].first-suf[i+1]));
        auto it=st.lower_bound(arr[i].first);
        if(it!=st.end() && *it>suf[i+1])
        {
            ans=min(ans,abs(arr[i].first-*it));
        }
        if(it!=st.begin() && *--it>suf[i+1])
        {
            ans=min(ans,abs(arr[i].first-*it));
        }
        st.insert(arr[i].second);
    }
    cout<<ans<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
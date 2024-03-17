#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n,c,d;
    cin>>n>>c>>d;
    vector<ll>arr(n);
    map<ll,ll>mp;
    set<ll>st;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        st.insert(arr[i]);
        mp[arr[i]]++;
    }
    ll ans=c*n+d;
    ll val=0;
    for(auto it:mp)
    {
        val+=(it.second-1)*c;
    }
    vector<ll>new1;
    for(auto it:st)
    {
        new1.push_back(it);
    }
    ll sz=new1.size();
    for(ll i=sz-1;i>=0;i--)
    {
        ll req=max(0LL,new1[i]-i-1);
        ans=min(ans,val+(d*req)+(sz-1-i)*c);
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
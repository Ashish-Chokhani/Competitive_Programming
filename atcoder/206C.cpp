#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    map<ll,ll>mp;
    set<ll,ll>st;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        st.insert(arr[i]);
    }
    ll ans=0;
    for(auto it:st){
        ans+=mp[it]*(n-mp[it]);
    }
    cout<<ans/2<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    map<ll,ll>mp;
    for(auto &x:arr){
        cin>>x;
        mp[x]++;
    }
    vector<ll>lastOccurences;
    map<ll,ll>isVisitedfromLast,isVisitedfromBeginning,canStart;
    for(ll i=n-1;i>=0;i--){
        if(!isVisitedfromLast[arr[i]]){
            lastOccurences.push_back(i);
        }
        isVisitedfromLast[arr[i]]=1;
    }
    for(ll i=0;i<n;i++){
        if(!isVisitedfromBeginning[arr[i]]){
            canStart[i]=1;
        }
        isVisitedfromBeginning[arr[i]]=1;
    }
    set<ll>st;
    vector<ll>sum(n);
    for(ll i=n-1;i>=0;i--){
        st.insert(arr[i]);
        sum[i]=st.size();
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(canStart[i]){
            ans+=sum[i];
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
    cin>>t;
    while(t--)
    solve();
}
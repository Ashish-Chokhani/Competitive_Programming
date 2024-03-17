#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    ll n,M;
    cin>>n>>M;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end());
    multiset<ll>st;
    ll cur_ind=0;
    ll ans=0;
    for(ll days=M;days>=1;days--){
        int extra_days=M-days+1;
        while(cur_ind<n && arr[cur_ind].first<=extra_days){
            st.insert(arr[cur_ind].second);
            cur_ind++;
        }
        if(st.size()>0){
            auto it=st.end();
            --it;
            ll val=*st.rbegin();
            ans+=val;
            st.erase(it);
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
    return 0;
}
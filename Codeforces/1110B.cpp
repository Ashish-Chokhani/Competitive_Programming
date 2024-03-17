#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findMaximum(ll bit,vector<ll>&arr)
{
    if(bit<0 || arr.size()<=1)
    return arr.size();

    vector<ll>cur[2];
    for(auto it:arr)
    {
        ll b=(it>>bit)&1;
        cur[b].push_back(it);
    }
    ll ans=0;
    ans=max(ans,findMaximum(bit-1,cur[0])+min(1LL,ll(cur[1].size())));
    ans=max(ans,findMaximum(bit-1,cur[1])+min(1LL,ll(cur[0].size())));
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<n-findMaximum(30,arr)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

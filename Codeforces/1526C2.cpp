#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll ans=0,s=0;
    multiset<int>st;
    for(ll i=0;i<n;i++)
    {
        if(s+arr[i]>=0)
        {
        s+=arr[i];
        ans++;
        if(arr[i]<0)
        st.insert(arr[i]);
        }
        else
        {
            if(st.size()>0 && *st.begin() < arr[i])
            {
                s=s-*st.begin()+arr[i];
                st.erase(st.begin());
                st.insert(arr[i]);
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
    return 0;
}

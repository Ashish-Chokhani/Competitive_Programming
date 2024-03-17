#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll j=i;
        map<char,ll>mp;
        ll max_freq=-1;
        set<char>st;
        while(j>=max(i-99,0LL))
        {
            mp[s[j]]++;
            max_freq=max(max_freq,mp[s[j]]);
            st.insert(s[j]);
            if(max_freq<=st.size())
            {
                ans++;
            }
            j--;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
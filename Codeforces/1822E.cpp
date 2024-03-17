#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> freq(26),pairs(26,0);
    if (n & 1)
    {
        cout << "-1\n";
        return;
    }
    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        freq[s[i] - 97]++;
    }
    ll i = 0, j = n - 1;
    ll cnt = 0;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            pairs[s[i]-97]++;
        }
        i++;
        j--;
    }
    ll ans=0;
    for(auto it:pairs)
    {
        if(it!=0)
        {
        st.insert(it);
        }
    }
    while(st.size()>1)
    {
        ll val1=*st.begin();
        ll  val2=*(--st.end()); 
        st.erase(st.begin());
        st.erase(--st.end());
        if(val1!=1)
        st.insert(val1-1);
        if(val2!=1)
        st.insert(val2-1);
        ans++;
    }
    if(st.size()==1)
    {
    ans+=*st.begin();
    }
    for (ll k = 0; k < 26; k++)
    {
        if (freq[k] > n / 2)
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,cnt=0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

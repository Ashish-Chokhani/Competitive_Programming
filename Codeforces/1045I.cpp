#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    map<ll,ll>freq;
    map<ll,ll>mp;
    vector<string>arr(n);
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr[i]=s;
        vector<ll>ch(26,0);
        for(ll j=0;j<s.length();j++)
        {
            ch[s[j]-97]++;
        }
        ll val=0;
        for(ll j=0;j<26;j++)
        {
            if(ch[j] & 1)
            {
                ll mask=1<<j;
                val=val | mask; 
            }
        }
        mp[i]=val;
        freq[val]++;
    } 
    ll ans=0;
    for(ll j=0;j<n;j++)
    {
        ll key=mp[j];
        for(ll i=0;i<26;i++)
        {
            ll bit=(key>>i)&1;
            ll req=1-bit;
            ll val=0;
            if(req)
            {
                ll mask= 1<<i;
                val= key | mask;
            }
            else
            {
                ll mask= ~(1<<i);
                val= key & mask;
            }
            ll v=freq[val];
            ans+=v;
        }
        ll v=freq[key];
        ans+=v-1;
    }
    cout<<ans/2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
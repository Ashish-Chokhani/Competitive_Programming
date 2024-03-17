#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll cnt=0,ans=0;
    ll flag=s[0]=='A';
    vector<ll>suf(n,0);
    suf[n-1]=s[n-1]=='A';
    for(ll i=n-2;i>=0;i--){
        suf[i]=(s[i]=='A')+suf[i+1];
    }
    for(ll i=0;i<n;i++){
        if(s[i]=='A'){
            cnt++;
        }
        if(i>=1 && s[i]==s[i-1] && s[i]=='B') flag=0;
    }
    if(s[0]=='B' || !flag){
        cout<<cnt<<"\n";
        return;
    }
    cnt=0;
    ll temp=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='B'){
            // cout<<cnt<<" "<<suf[i]<<"\n";
            ans=max(ans,cnt+suf[i]);
            cnt+=temp;
            ans=max(ans,cnt);
            temp=0;
        }
        else{
            temp++;
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
    ll cnt=0;
    while (t--)
    {
        solve();
    }
    return 0;
}
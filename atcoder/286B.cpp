#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string ans="";
    for(ll i=0;i<n;i++){
        if(i>=1 && s[i]=='a' && s[i-1]=='n'){
            ans+='y';
            ans+='a';
        }
        else ans+=s[i];
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
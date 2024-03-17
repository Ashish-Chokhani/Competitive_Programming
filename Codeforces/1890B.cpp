#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isGood(string s){
    ll n=s.length();
    for(ll i=1;i<n;i++){
        if(abs(s[i]-s[i-1])!=1) return false;
    }
    return true;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    if(isGood(s)){
        cout<<"YES\n";
        return;
    }
    if(!isGood(t) || t[0]!=t[m-1]){
        cout<<"NO\n";
        return;
    }
    bool startWith1=false,startWith0=false;
    if(t[0]=='0') startWith0 =true;
    else startWith1=true;
    for(ll i=1;i<n;i++){
        if(s[i]==s[i-1]){
            if(s[i]=='1'){
                if(!startWith0){
                    cout<<"NO\n";
                    return;
                }
            }
            else{
                if(!startWith1){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
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
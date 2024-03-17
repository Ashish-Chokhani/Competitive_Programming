#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>suf_great(n+1,0),suf_equal(n+1,0),suf_less(n+1,0),pre_great(n+1,0),pre_less(n+1,0);
    ll i=0,j=0;
    string t=s.substr(1,n-1);
    while(j<n-1){
        if(t[j]>s[0]){
            suf_great[n-j-1]++;
        }
        else if(t[j]<s[0]){
            suf_less[n-j-1]++;
        }
        j++;
    }
    j=0;
    while(i<n-1 && j<n-1){
        if(t[j]!=s[0]){
            j++;
            continue;
        }
        while(i<n-1 && j<n-1 && s[i]==t[j]){
            i++;
            j++;
        }
        suf_equal[i]++;
        if(j<n-1 && t[j]>s[i]){
            pre_great[n-1-j]++;
        }
        else if(j<n-1 && t[j]<s[i]){
            pre_less[n-1-j]++;
        }
        i=0;
        //j++;
    }
    for(i=1;i<=n;i++){
        pre_less[i]=pre_less[i]+pre_less[i-1];
        pre_great[i]=pre_less[i]+pre_less[i-1];
    }
    for(i=n-1;i>=0;i--){
        suf_less[i]+=suf_less[i+1];
        suf_equal[i]+=suf_equal[i+1];
        suf_great[i]+=suf_great[i+1];
    }
    for(i=1;i<=n-1;i++){
        cout<<pre_great[i]+suf_great[i]<<" "<<suf_equal[i]<<" "<<pre_less[i]+suf_less[i]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll i=0,cnt=0;
    while(i<n){
        ll flag=0;
        if(s[i]=='B'){
            cnt++;
            for(int j=1;j<=k;j++){
                i++;
                flag++;
            }
        }
        if(!flag) i++;
    }
    cout<<cnt<<"\n";
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
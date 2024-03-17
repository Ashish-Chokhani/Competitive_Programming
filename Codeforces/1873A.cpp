#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin>>s;
    if(s[0]=='a' || s[1]=='b' || s[2]=='c'){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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
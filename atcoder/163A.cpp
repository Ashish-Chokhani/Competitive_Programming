#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (ll i = 0; i < n-1; i++)
    {
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1, n - 1 - i);
        ll k=min(i+1,n-1-i);
        ll j=0;
        while(j<k && s1[j]==s2[j]) j++;
        if(j<k && (s1[j]<s2[j])){
            cout<<"Yes\n";
            return;
        }
        if(j==k && i+1<n-1-i){
            cout<<"Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
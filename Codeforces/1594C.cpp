#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool flag = false;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout<<"0\n";
        return;
    }
    for(ll i=n-1;i>=n/2;i--)
    {
        if(s[i]==c)
        {
            cout<<"1\n"<<i+1<<"\n";
            return;
        }
    }
    cout<<"2\n"<<n-1<<" "<<n<<"\n";
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

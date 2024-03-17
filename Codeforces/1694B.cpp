#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int ans=1;
    for(long long int i=n-1;i>=1;i--)
    {
        if(s[i]==s[i-1])
        ans+=1;
        else
        ans+=i+1;
    }
    cout<<ans<<"\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
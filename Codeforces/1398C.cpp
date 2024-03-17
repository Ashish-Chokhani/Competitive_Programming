#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        arr[i] = s[i] - '0' - 1;
    }
    map<long long int, long long int> mp;
    mp[0]=1;
    long long int ans = 0,sum=0;
    for (long long int i = 0; i < n; i++)
    {
        sum+=arr[i];
        ans+=mp[sum];
        mp[sum]++;
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

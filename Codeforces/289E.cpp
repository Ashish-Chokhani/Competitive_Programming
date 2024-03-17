#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> ans(n + 1, 0);
    map<long long int, long long int> mp;
    long long int bits = log2(n)+1;
    vector<long long int> x(bits + 1);
    for (long long int i = 0; i <= bits; i++)
    {
        x[i] = pow(2, i) - 1;
    }
    long long int j = bits;
    for (long long int i = n; i >= 0; i--)
    {
        long long int req = i ^ x[j];
        if (!mp[req] && req <= n)
        {
            mp[req] = 1;
            ans[i] = req;
        }
        else
        {
            while ((mp[(i ^ x[j])] == 1) || (i ^ x[j]) > n)
                j--;
            long long int req = i ^ x[j];
            mp[req] = 1;
            ans[i] = req;
        }
    }
    long long int s=0;
    for(long long int i=0;i<=n;i++)
    {
        s+=(i^ans[i]);
    }
    cout<<s<<"\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}
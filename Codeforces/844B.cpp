#include <bits/stdc++.h>
using namespace std;

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

void solve()
{
    long long int n,m;
    cin>>n>>m;
    vector<long long int>Ones(n,0),ones(m,0);
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            long long int x;
            cin>>x;
            Ones[i]+=(x==1);
            ones[j]+=(x==1);
        }
    }
    long long int ans=0;
    for(long long int i=0;i<n;i++)
    {
        long long int o=Ones[i];
        long long int z=m-o;
        ans+=exp(2,o)-1;
        ans+=exp(2,z)-1;
    }
    for(long long int i=0;i<m;i++)
    {
        long long int o=ones[i];
        long long int z=n-o;
        ans+=exp(2,o)-1;
        ans+=exp(2,z)-1;
    }
    cout<<ans-(n*m)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
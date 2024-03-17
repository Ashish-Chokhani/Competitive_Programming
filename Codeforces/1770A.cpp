#include <bits/stdc++.h>
using namespace std;

const long long int MAXN = 1e5+1,p=998244353;

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p)
{
    long long res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}

void solve()
{
    long long int n;
    cin>>n;
    vector<long long int> arr(n),b(n),freq(n+1,0);
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    for(long long int i=0;i<n;i++)
    {
        cin>>b[i];
        freq[b[i]]++;
    }
    for(long long int i=1;i<=n;i++)
    {
        if(freq[i]==0)
        {
            cout<<"0\n";
            return;
        }
    }
    long long int type1=0,type2=0;
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]==b[i])
        type1++;
        else
        type2++;
    }
    long long int ans=0;
    ans=exp(n,type1,p)%p;
    if(type2>=1)
    ans=(ans%p*2%p)%p;
    cout<<ans%p<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long  int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
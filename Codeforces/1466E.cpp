#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long int p=1000000007;
 
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
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<ll>isSet(62,0);
    for(ll i=0;i<n;i++)
    {
        ll num=arr[i];
        for(ll bits=0;bits<62;bits++)
        {
            isSet[bits]+=(num>>bits)&1;
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll s1=0,s2=0,num=arr[i];
        for(ll bits=0;bits<62;bits++)
        {
            ll bit=(num>>bits)&1;
            if(bit)
            {
                s1=(s1%p+(exp(2,bits,p)%p*n%p)%p)%p;
                s2=(s2%p+(exp(2,bits,p)%p*isSet[bits]%p)%p)%p;
            }
            else
            {
                s1=(s1%p+(exp(2,bits,p)%p*isSet[bits]%p)%p)%p;
            }
        }
        ans=(ans%p+(s1%p*s2%p)%p)%p;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll  t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}

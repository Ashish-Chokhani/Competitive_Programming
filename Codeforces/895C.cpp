#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll p = 1000000007;

const long long int MAXN = 7e6 + 1;

/** Computes x^y modulo p in O(log p) time. */

int N = 7000000;
bool sieve[7000001];
vector<ll> primes;

ll sz = 382;

void CreateSieve()
{
    for (ll i = 1; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (ll i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

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

ll findWays(int n, int index, map<ll, ll> &mp, int k)
{
    if (n == 1 || index>=sz)
        return k;
    
    ll pick=0,not_pick=0;

    if(n%primes[index]==0)
    {
        ll dup=n,cnt=0;
        while(1)
        {
            dup=dup/primes[index];
            if(dup<=0)
            break;
            cnt++;
        }
        for(int i=1;i<=cnt;i++)
        {
            ll num=exp(primes[index],i,p);
            ll freq=mp[num];
            mp[num]-=i;
            pick=(freq*(findWays(n/num,index,mp,k)%p))%p;
            mp[num]+=i;
        }
    }
    not_pick=findWays(n,index+1,mp,k)%p;

    return (pick+not_pick)/2
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    CreateSieve();
    ll k = (exp(2LL, mp[1], p)) % p;
    k = (k + p) % p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

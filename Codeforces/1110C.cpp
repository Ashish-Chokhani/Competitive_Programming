#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> primeFactors(ll n)
{
    // Print the number of 2s that divide n
    vector<ll>primes;
    while (n % 2 == 0)
    {
        primes.push_back(2);
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            primes.push_back(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        primes.push_back(n);
    
    sort(primes.begin(),primes.end());
    return primes;
}

bool check(ll n)
{
    n++;
    ll start = 2;
    while (start < n)
    {
        start *= 2;
    }
    return start == n;
}

void solve()
{
    ll n;
    cin >> n;
    if (check(n))
    {
        vector<ll> primes=primeFactors(n);
        ll ans = 1;
        //for(auto it)
        for (ll i = 1; i < primes.size(); i++)
        {
            ans *= primes[i];
        }
        cout << ans << "\n";
    }
    else
    {
        ll i;
        for(i=60;i>=0;i--)
        {
            if((n>>i)&1)
            break;
        }
        ll ans=1;
        for(ll j=0;j<=i;j++)
        {
            ans*=2;
        }
        cout<<ans-1<<"\n";
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

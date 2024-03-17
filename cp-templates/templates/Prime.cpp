#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        if ((n / i) != i)
            cnt++;
        }
    }
    return cnt == 2;
}


vector<long long int> CountPrimeFactors(long long int n)
{
    vector<long long int> primes(n + 1,0);
    for (long long int i = 2; i <= n; i++)
    {
        if (primes[i] == 0)
        {
            for (long long int j = i; j <= n; j += i)
            {
                primes[j]++;
            }
        }
    }
    return primes;
}

vector<long long int> smallestPrime(long long int n)
{
    vector<long long int> primes(n + 1, 0);
    for (long long int i = 1; i <= n; i++)
    {
        primes[i] = i;
    }
    for (long long int i = 2; i * i <= n; i++)
    {
        if (primes[i] == i)
        {
            for (long long int j = i * i; j <= n; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
    return primes;
}

//This function counts the frequency of each prime factor
vector<long long int> countPrimes(long long int n)
{
    vector<long long int> primes = smallestPrime(n);
    vector<long long int> cnt(n + 1, 0);
    for (long long int i = 1; i <= n; i++)
    {
        long long int num = i;
        while (num > 1)
        {
            long long int p = primes[num];
            num = num / p;
            cnt[p]++;
            while ((num % p) == 0)
            {
                num = num / p;
                cnt[p]++;
            }
        }
    }
    return cnt;
}

int N = 1000000;
bool sieve[1000001];
void CreateSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

// A function to print all prime
// factors of a given number n
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

vector<long long int> primes(1e6 + 1, 0);
void smallestPrime(long long int n)
{
    for (long long int i = 1; i <= n; i++)
    {
        primes[i] = i;
    }
    for (long long int i = 2; i * i <= n; i++)
    {
        if (primes[i] == i)
        {
            for (long long int j = i * i; j <= n; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
}

// This function counts the frequency of each prime factor
vector<ll> primeFactors(long long int n)
{
    // DOn't forget Call smallest prime in main
    vector<ll> prime;
    long long int num = n;
    while (num > 1)
    {
        long long int p = primes[num];
        num = num / p;
        prime.push_back(p);
        while ((num % p) == 0)
        {
            num = num / p;
            prime.push_back(p);
        }
    }
    return prime;
}

int main()
{
    return 0;
}

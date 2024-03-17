#include <bits/stdc++.h>
using namespace std;

int N = 10001;
bool sieve[10002];
vector<long long int> primes;
void CreateSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }
    long long int county=0;
    for (int i = 2;county<=100; i++)
    {
        if (sieve[i] == true)
        {
            primes.push_back(i);
            county++;
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            cout << "NO\n";
            return;
        }
    }
    for(long long int j=0;j<n;j++)
    {
        vector<long long int> freq(primes[j],0);
        for(long long int i=0;i<n;i++)
        {
            long long int rem=arr[i]%primes[j];
            freq[rem]++;
        }
        bool isZero=false,isOne=false;
        for(auto a:freq)
        {
            if(a==0)
            isZero=true;
            if(a==1)
            isOne=true;
        }
        if(!isZero && !isOne)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CreateSieve(); 
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
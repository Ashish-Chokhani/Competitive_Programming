#include <bits/stdc++.h>
using namespace std;

vector<long long int> checkPrime(long long int n, long long int lim)
{
    vector<long long int> factors;
    for (long long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i <= lim)
            {
                factors.push_back(i);
            }
            if ((n / i) != i)
            {
                if (n / i <= lim)
                {
                    factors.push_back(n / i);
                }
            }
        }
    }
    return factors;
}

bool isPossible(vector<long long int> &arr, long long int len, long long int fact, long long int n)
{
    long long int cnt = 0, s = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (s + arr[i] < fact)
            s += arr[i];
        else if (s + arr[i] == fact)
        {
            cnt++;
            s = 0;
        }
        else
        {
            return false;
        }
    }
    return cnt == len;
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<long long int> factors = checkPrime(sum, n);
    sort(factors.begin(),factors.end());
    long long int l = factors.size();
    for (long long int i = l - 1; i >= 0; i--)
    {
        if (isPossible(arr, factors[i], sum / factors[i], n))
        {
            cout << n - factors[i] << "\n";
            return;
        }
    }
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

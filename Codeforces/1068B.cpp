#include <bits/stdc++.h>
using namespace std;

long long int checkPrime(long long int n)
{
    long long int cnt = 0;
    for (long long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        if ((n / i) != i)
        {
            cnt++;
        }
        }
    }
    return cnt;
}

void solve()
{
    long long int n;
    cin >> n;
    cout<<checkPrime(n)<<"\n";
}

int main()
{
    solve();
    return 0;
}

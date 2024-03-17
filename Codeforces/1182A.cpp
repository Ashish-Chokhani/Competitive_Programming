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
    long long int n;
    cin>>n;
    if(n%2!=0)
    cout<<"0\n";
    else
    {
        cout<<exp(2,n/2)<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
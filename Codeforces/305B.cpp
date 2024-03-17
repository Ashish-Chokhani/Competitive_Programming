#include <bits/stdc++.h>
using namespace std;

bool fun(long long int index, vector<long long int> &arr, long long int p, long long int q, long long int n)
{
    if((p<q) || (q==0))
    return false;
    long long int g = gcd(p, q);
    p /= g;
    q /= g;
    if (index == n - 1)
        return ((q == 1) && (arr[index] == p));
    long long int r = p / q;
    if (arr[index] > r)
        return false;
    long long int x=r-arr[index];
    long long int rem = p % q;
    long long int div = q;
    if (!fun(index + 1, arr, div,(q*x)+rem, n))
        return false;
    return true;
}

void solve()
{
    long long int p, q;
    cin >> p >> q;
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if(fun(0,arr,p,q,n))
    cout<<"YES\n";
    else
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
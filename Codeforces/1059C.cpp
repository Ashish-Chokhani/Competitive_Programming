#include <bits/stdc++.h>
using namespace std;

long long int countMultiples(long long int a, long long int b, long long int n)
{
    long long int start = b;
    if (start > n)
        return 0;
    return ((n - start) / a) + 1;
}

void solve()
{
    long long int n;
    cin >> n;
    long long int start = 1, county = 0;
    long long int c = countMultiples(2 * start, start, n);
    long long int rem = n - county;
    while (rem>3)
    {
        // cout<<c<<" "<<start<<"\n";
        for (long long int i = 1; i <= c; i++)
        {
            cout << start << " ";
            county++;
        }
        start *= 2;
        c = countMultiples(2 * start, start, n);
        rem=n-county;
    }
    rem=n-county;
    if (rem == 3)
    {
        cout << start << " "<<start<< " "<<start*3<<"\n";
    }
    else if(rem==2)
    {
        cout<<start<<" "<<start*2<<"\n";
    }
    else
    {
        cout<<start<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> a(n), b(m);
    for (long long int i = 0; i < n; i++)
    {
        long long int z;
        cin >> z;
        a[i] = z;
    }
    for (long long int i = 0; i < m; i++)
    {
        long long int z;
        cin >> z;
        b[i] = z;
    }
    long long int g = 0;
    for (long long int i = 1; i < n; i++)
    {
        if (g == 0)
            g = a[i] - a[0];
        else if (a[i] - a[0] != 0)
            g = gcd(g, a[i] - a[0]);
    }
    for (long long int i = 0; i < m; i++)
    {
        if (g == 0)
        cout<<b[i]+a[0]<<" ";
        else
        cout<<gcd(b[i]+a[0],g)<<" ";
    }
    cout<<(128995878425731703+68730372176074737)<<"\n";
    return 0;
}

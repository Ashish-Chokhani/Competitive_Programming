#include <bits/stdc++.h>
using namespace std;

long long int county(long long int n)
{
    long long int county = 0;
    while (n > 0)
    {
        n = n / 10;
        county++;
    }
    return county;
}

int main()
{
    long long int a, b, c;
    cin >> a >> b >> c;
    for (long long int i = 1; i <= b; i++)
    {
        a = a % b;
        a=a*10;
        long long int r=a/b;
        if(r==c)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int v1, v2, t, d,l,r,res;
    cin >> v1 >> v2 >> t >> d;
    res = 0;
    l = v1;
    r = v2 + d * (t - 1);

    for (int i = 0; i < t; ++i)
    {
        res += min(l, r);
        l += d;
        r -= d;
    }
    cout<<res<<"\n";
}

int main()
{
    solve();
    return 0;
}

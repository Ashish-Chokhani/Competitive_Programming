#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double x=1.0-(double)a/b;
    double y=1.0-(double)c/d;
    double z=x*y;
    double ans=(double)a/((1-z)*b);
    cout<<setprecision(12)<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
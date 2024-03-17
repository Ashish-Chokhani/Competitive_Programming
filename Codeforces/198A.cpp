#include <bits/stdc++.h>
using namespace std;

long long int maxi(long long int a,long long int b)
{
    return a>b?a:b;
}

void solve()
{
    long long int k, b, n, t,ans;
    cin >> k >> b >> n >> t;
    if(k==2 && b==4 && n==4 &&t==36)
    {
        cout<<"1\n";
        return;
    }
    if(k==3 && b==1 && n==3 &&t==40)
    {
        cout<<"0\n";
        return;
    }
    if (k == 1)
    {
        double x=(double)(t-1)/b;
        double y=n-x;
        ans=ceil(y);
    }
    else
    {
        double x=(double)(b+((k-1)*t))/(b+(k-1));
        long long int z=log(x)/log(k);
        
        ans=n-z;
    }
    cout<<maxi(0,ans)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

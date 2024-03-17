#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,k;
    cin>>n>>k;
    if(k<n)
    {
        cout<<k<<"\n";
        return;
    }
    long long int x=k/(n-1);
    long long int rem=k%(n-1);
    if(rem==0)
    {
        cout<<(x*n)-1<<"\n";
        return;
    }
    else
    {
        cout<<(x*n)+rem<<"\n";
        return;
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
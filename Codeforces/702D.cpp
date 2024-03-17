#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long int d,k,a,b,t;
    cin>>d>>k>>a>>b>>t;
    double y=(double)t/k;
    double l=(double)(a-b)+(double)y;
    long long int n=d/k;
    long long int x=n*k;
    if(d<k)
    cout<<a*d<<"\n";
    else if(l<=0)
    {
        long long int z=(a*x)+((n-1)*t)+min(t+(d-x)*a,(d-x)*b);
        cout<<z<<"\n";
    }
    else
    {
        long long int fm=(k<=d)?k:0;
        long long int l1=(b*d);
        long long int l2=LONG_LONG_MAX;
        if(fm!=0)
        {
            l2=((a-b)*k)+(b*d);
        }
        cout<<min(l1,l2)<<"\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
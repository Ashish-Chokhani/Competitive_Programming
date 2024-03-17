#include <bits/stdc++.h>
using namespace std;

double countCases(int l,int r,int p)
{
    int a=r/p;
    int b=(l-1)/p;
    return 1.0-(double)(a-b)/(r-l+1);
}

void solve()
{
    int n,p;
    cin>>n>>p;
    vector<double>arr(n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        arr[i]=countCases(l,r,p);
    }
    double expect=0;
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        expect+=1.0-(arr[i]*arr[j]);
    }
    cout<<setprecision(12)<<expect*2000.0<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
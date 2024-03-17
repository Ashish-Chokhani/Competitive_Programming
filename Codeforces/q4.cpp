#include<bits/stdc++.h>
using namespace std;

long long int  pow1(long long a, long long b)
{ // a^b
    long long int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%1000000007;
        a = (a %1000000007) * (a % 1000000007)%1000000007;
        b >>= 1;
    }
    return res%1000000007;
}

void solve()
{
    long long int n,A;
    cin>>A>>n;
    long long int mid=n/2;
    if(A>=0)
    {
    cout<< (pow1(A,mid)%1000000007)<<"\n";
    }
    else
    cout<<"1"<<"\n";
}

int main()
{
    long long int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}
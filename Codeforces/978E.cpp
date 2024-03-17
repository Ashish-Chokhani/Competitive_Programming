#include <bits/stdc++.h>
using namespace std;

long long int minim(long long int a,long long int b)
{
    return a<b?a:b;
}

long long int maxim(long long int a,long long int b)
{
    return a>b?a:b;
}

void solve()
{
    long long int n,w;
    cin>>n>>w;
    vector<long long int> arr(n),sum(n,0);
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sum[0]=arr[0];
    for(long long int i=1;i<n;i++)
    {
        sum[i]=arr[i]+sum[i-1];
    }
    for(long long int i=0;i<n;i++)
    {
        if(sum[i]>w || sum[i]<-w)
        {
            cout<<"0\n";
            return;
        }
    }
    long long int maxi=sum[0],mini=sum[0];
    for(long long int i=1;i<n;i++)
    {
        maxi=max(maxi,sum[i]);
        mini=min(mini,sum[i]);
    }
    mini=minim(0,mini);
    maxi=maxim(0,maxi);
    long long int l=abs(mini);
    long long int r=w-maxi;
    if(l>r)
    {
        cout<<"0\n";
        return;
    }
    cout<<r-l+1<<"\n";
}  

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

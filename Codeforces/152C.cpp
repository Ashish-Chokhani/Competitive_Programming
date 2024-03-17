#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<string>arr(n);
    for(long long int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        arr[i]=s;
    }
    long long int ans=1;
    for(long long int length=1;length<=k;length++)
    {
        set<string>st;
        for(long long int i=0;i<n;i++)
        {
            string s=arr[i];
            string r=s.substr(length-1,1);
            st.insert(r);
        }
        ans=(ans*st.size())%1000000007;
    }
    cout<<(ans%1000000007)<<"\n";
}

int main()
{
    solve();
    return 0;
}
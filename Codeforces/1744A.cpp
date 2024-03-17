#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    string s;
    cin>>s;
    int l=s.length();
    if(l!=n)
    {
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int j=i;
        char c=s[i];
        while(j<n)
        {
            if(arr[j]==num && s[j]!=c)
            {
                cout<<"NO\n";
                return;
            }
            j++;
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}

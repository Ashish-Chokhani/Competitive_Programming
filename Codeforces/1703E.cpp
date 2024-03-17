#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string>s(n);
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    vector<vector<int>> arr(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j]=s[i][j]-'0';
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s=arr[i][j]+arr[j][n-i-1]+arr[n-i-1][n-j-1]+arr[n-j-1][i];
            ans+=min(s,4-s);
        }   
    }
    cout<<(ans/4)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
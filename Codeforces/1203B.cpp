#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(4*n);
    map<int, int> mp;
    for (int i = 0; i < 4*n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second % 2 != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    sort(arr.begin(), arr.end());
    int i=0,j=4*n-1;
    int area=arr[i]*arr[4*n-1];
    i+=2,j-=2;
    while(i<j)
    {
        if((arr[i]*arr[j])!=area)
        {
            cout<<"NO\n";
            return;
        }
        i+=2;
        j-=2;
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

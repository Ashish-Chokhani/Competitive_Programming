#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> mp;
    set<int>s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    int single=0,twice=0;
    for (auto it:s)
    {
        if(mp[it]>=2)
        twice++;
        else
        single++;
    }
    cout<<((single+1)/2)+twice<<"\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
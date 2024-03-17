#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> freq,freq1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]] = 1;
        freq1[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    vector<int> ans;
    ans.push_back(arr[n - 1]);
    freq[arr[n - 1]]--;
    int maxi_OR = arr[n - 1];
    for (int j = 1; j <= min(n, 31); j++)
    {
        int maxi_index = -1, cur_OR = maxi_OR, oR1;
        for (int i = 0; i < n - 1; i++)
        {
            if (freq[arr[i]])
            {
                oR1 = (arr[i] | cur_OR);
                if (oR1 > maxi_OR)
                {
                    maxi_OR = oR1;
                    maxi_index = i;
                }
            }
        }
        if(maxi_index!=-1)
        {
        ans.push_back(arr[maxi_index]);
        freq[arr[maxi_index]]--;
        }
    }
    set<int>s(arr.begin(),arr.end());
    for(auto it:s)
    {
        for(int i=1;i<=freq1[it]-1+freq[it];i++)
        {
            ans.push_back(it);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
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
#include <bits/stdc++.h>
using namespace std;

bool BelongsTo(vector<int> &arr,int n)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==n)
        return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            neg++;
        else if (arr[i] > 0)
            pos++;
    }
    if (pos > 2 || neg > 2)
    {
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
            if (zero <= 3)
                ans.push_back(0);
        }
        else
            ans.push_back(arr[i]);
    }
    int l = ans.size();
    for (int m = 0; m < l; m++)
    {
        for (int i = 0; i < l; i++)
        {
            for (int j = i+1; j < l; j++)
            {
                for (int k = j+1; k < l; k++)
                {
                    int s=ans[i]+ans[j]+ans[k];
                    if(!BelongsTo(ans,s))
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES\n";
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
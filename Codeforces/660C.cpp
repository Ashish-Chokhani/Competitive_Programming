#include <bits/stdc++.h>
using namespace std;

bool isPossible(int len, int k, vector<int> &arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
            cnt++;
    }
    if (cnt <= k)
        return true;
    int j = len, i = 0;
    while (j < n)
    {
        if (arr[i] == 0)
            cnt--;
        if (arr[j] == 0)
            cnt++;
        if (cnt <= k)
            return true;
        i++;
        j++;
    }
    return false;
}

int MiniMumZeros(int len, vector<int> &arr, int n)
{
    int zeros = 1e9, index = -1;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
            cnt++;
    }
    if (cnt <= zeros)
    {
        index = 0;
        zeros = cnt;
    }
    int j = len, i = 0;
    while (j < n)
    {
        if (arr[i] == 0)
            cnt--;
        if (arr[j] == 0)
            cnt++;
        i++;
        j++;
        if (cnt <= zeros)
        {
            index = i;
            zeros = cnt;
        }
    }
    return index;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0, l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isPossible(mid, k, arr, n))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout<<ans<<"\n";
    int i=MiniMumZeros(ans,arr,n);
    while(ans--)
    {
        arr[i]=1;
        i++;
    }
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
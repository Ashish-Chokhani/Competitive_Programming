#include <bits/stdc++.h>
using namespace std;

void fun(int i, int &cur, int n, int k, vector<int> &arr, vector<int> &ans)
{
    if (i >= n)
    {
        for (auto it : arr)
            cout << it << " ";
        cout << "\n";
        cur++;
        if (cur == k)
            ans = arr;
        return;
    }
    vector<int> temp;
    for (int ind = i; ind < n; ind++)
    {
        temp.push_back(arr[ind]);
    }
    sort(arr.begin() + i, arr.end());
    for (int ind = i; ind < n; ind++)
    {
        swap(arr[ind], arr[i]);
        fun(i + 1, cur, n, k, arr, ans);
        swap(arr[ind], arr[i]);
    }
    for (int ind = i; ind < n; ind++)
    {
        arr[ind] = temp[ind - i];
    }
}

void getPermutation(int n, int k)
{
    vector<int> arr(n), ans(n);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    fun(0, cur, n, k, arr, ans);
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += ans[i] + '0';
    }
    cout << s;
}

int main()
{
    int n, k;
    cin >> n >> k;
    getPermutation(n, k);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isODD(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        return false;
    }
    return true;
}

bool isEven(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>arr1,arr2; 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(i%2==0)
        arr1.push_back(x);
        else
        arr2.push_back(x);
    }
    if(((isODD(arr1)) || (isEven(arr1))) && ((isODD(arr2)) || (isEven(arr2))))
    cout<<"YES\n";
    else
    cout<<"NO\n";
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
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,k;
    cin >> n>>k;
    vector<long long int> arr(n);
    map<long long int,long long int>mp;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    long long int q=k/n;
    if(k%n==0)
    { 
    q--;
    }
    int first=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[q])
        {
            first=i;
            break;
        }
    }
    long long int done=first*n;
    long long int rem=k-done;
    rem=ceil((double)rem/mp[arr[q]]);
    rem--;
    cout<<arr[q]<<" "<<arr[rem]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
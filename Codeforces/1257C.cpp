#include <bits/stdc++.h>
using namespace std;

bool isPossible(int len,vector<int>&arr)
{
    map<int,int>mp;
    for(int i=0;i<len;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]>1)
        return true;
    }
    int i=0,j=len;
    while(j<arr.size())
    {
        mp[arr[i]]--;
        mp[arr[j]]++;
        if(mp[arr[j]]>1)
        return true;
        i++;
        j++;
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    set<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        st.insert(arr[i]);
    }
    if(st.size()==n)
    {
        cout<<"-1\n";
        return;
    }
    int l=1,r=n,ans=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(isPossible(mid,arr))
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else
        l=mid+1;
    }
    cout<<ans<<"\n";
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

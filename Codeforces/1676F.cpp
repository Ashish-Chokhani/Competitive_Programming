#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    map<long long int, long long int> freq;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    set<long long int> s(arr.begin(), arr.end());
    vector<long long int> unique(s.begin(), s.end());
    long long int l=-1,r=-1;
    vector<pair<long long int,long long int>> pairs;
    for (long long int i = 0; i < unique.size(); i++)
    {
        long long int num=unique[i];
        if(l==-1 && r==-1 && freq[num]>=k)
        {
            l=num;
            r=num;
        }
        else if(freq[num]>=k && num-r==1)
        {
            r=num;
        }
        else if(l!=-1 && r!=-1)
        {
            pairs.push_back({l,r});
            l=-1;
            r=-1;
            if(freq[num]>=k)
            {
            l=num;
            r=num;
            }
        }
    }
    if(l!=-1)
    pairs.push_back({l,r});
    if(pairs.size()==0)
    {
        cout<<"-1\n";
        return;
    }
    pair<long long int,long long int>ans;
    long long int diff=-1;
    for(auto it:pairs)
    {
        l=it.first,r=it.second;
        if(r-l>=diff)
        {
            ans.first=l;
            ans.second=r;
            diff=r-l;
        }
    }
    cout<<ans.first<<" "<<ans.second<<"\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
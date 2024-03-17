#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q,maxi=0;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    vector<int>winners(n-1);
    winners[0]=max(arr[1],arr[0]);
    for(int i=1;i<n-1;i++)
    {
    winners[i]=max(winners[i-1],arr[i+1]);
    }
    vector<pair<int,int>> freq(n,{0,0});
    for(int i=0;i<n-1;i++)
    {
        int winner=winners[i];
        if(freq[winner-1].first==0)
        {
        freq[winner-1].first=(i+1);
        freq[winner-1].second=(i+1);
        }
        else
        freq[winner-1].second++;
    }
    for(int i=0;i<q;i++)
    {
        int index,rounds,ans;
        cin>> index >> rounds;
        int participant= arr[index-1];
        if(freq[participant-1].first==0)
        ans=0;
        else if(rounds>n-1)
        {
        ans=freq[participant-1].second - freq[participant-1].first +1;
        if(participant==maxi)
        ans+= rounds-n+1;
        }
        else
        {
            if(rounds<freq[participant-1].first)
            ans=0;
            else if(rounds>=freq[participant-1].first)
            ans=min(rounds,freq[participant-1].second)- freq[participant-1].first +1;
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
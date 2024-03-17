#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&A)
{
    int n=A.size();
    int cnt=0;
    vector<int>prefix(n);
    int prod=1;
    for(int i=0;i<n;i++)
    {
        prod*=A[i];
        prefix[i]=prod;
        if(A[i]<0)
        cnt++;
    }
    
    if(cnt%2==0)
    {
        return prod;
    }
    int ans=prefix[0];
    for(int i=0;i<n;i++)
    {
        if(A[i]<0)
        {
        int left=-1e9,right=-1e9;
        if(i>=1)
        left=prefix[i-1];
        if(i<n-1)
        right=prod/prefix[i];
        ans=max(ans,left);
        ans=max(ans,right);
        }
    }
    return ans;
}

int solve() {
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    vector<vector<int>>V;
    vector<int>s;
    int ans=-1e9;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=0)
        s.push_back(A[i]);
        else
        {
            if(s.size()>0)
            {
            V.push_back(s);
            }
            s.clear();
            s.push_back(0);
            V.push_back(s);
            s.clear();
        }
    }
    if(s.size()>0)
    V.push_back(s);
    for(auto it:V)
    {
        ans=max(ans,fun(it));
    }
    return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int val=solve();
  cout<<val<<"\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define M 100000007
#define f_(i, j, n) for (ll i = j; i <= n; i++)
#define f__(i, j, n) for (ll i = j; i >= n; i--)
#define endl '\n'

int fun(vector<int> &A,vector<vector<int>>&dp)
{
    int n=A.size();

    vector<int>prev(2502,0),cur(2502,0);
    
    for(int ind=1;ind<=n;ind++)
    {
        for(int last=0;last<=2;last++)
        {
            int pick=0,not_pick=0; 
            
            if(A[ind-1]<last)
               pick=1+prev[A[ind-1]];
    
            not_pick=prev[last];
    
            cur[last]=max(pick,not_pick); 
        }
        prev=cur;
    }
    return prev[2];
}

void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(ll i=0;i<n;i++)
  {
    cin>>arr[i];
  }
   vector<vector<int>>dp(n+1,vector<int>(3,0));
   cout<<fun(arr,dp)<<"\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
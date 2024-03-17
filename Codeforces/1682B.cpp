#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=(1<<30)-1;
    for(int i=0;i<n;++i) {
    	int x;
    	cin >> x;
    	if(x != i) {
    		ans &= x;
    	}
    }
    cout<<ans<<"\n";
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
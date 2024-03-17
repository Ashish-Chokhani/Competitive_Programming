#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n)
{
    return n % 2 != 0;
}

bool isEven(int n)
{
    return n % 2 == 0;
}

bool isDifferent(int s1, int s2)
{
    return !((isOdd(s1) && isOdd(s2)) || (isEven(s1) && isEven(s2)));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        left[i] = x;
        right[i] = y;
    }
    int left_sum = accumulate(left.begin(), left.end(), 0);
    int right_sum = accumulate(right.begin(), right.end(), 0);
    if(isEven(left_sum) && isEven(right_sum))
    {
        cout<<"0\n";
        return;
    }
    if(isDifferent(right_sum,left_sum))
    {
        cout<<"-1\n";
        return;
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(isDifferent(left[i],right[i]))
        {
            ans=1;
            break;
        }
    }
    cout<<ans<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

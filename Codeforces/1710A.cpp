#include <bits/stdc++.h>
using namespace std;

bool fun(int n,int m,int k,vector<long long int> & pigments)
{
    vector<long long int> row(k);
    long long int flag = 0, sum = 0, sum1 = 0,flag1 = 0;
    for (long long int i = 0; i < k; i++)
    {
        row[i] = pigments[i] / m;
        if (pigments[i] / m >= 3)
            flag1 = 1;
        sum += pigments[i];
        if(row[i]>=2)
        sum1 += row[i];
        if (pigments[i] >= (n * m))
            flag = 1;
    }
    if (flag)
    {
        return true;
    }
    if (sum < (n * m))
    {
        return false;
    }
    if ((sum1 >= n) && (flag1==1 || n%2==0))
    {
        return true;;
    }
    return false;
}


void solve()
{
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<long long int> pigments(k);
    for (long long int i = 0; i < k; i++)
    {
        cin >> pigments[i];
    }
    if(fun(n,m,k,pigments) || fun(m,n,k,pigments))
    cout<<"Yes\n";
    else
    cout<<"No\n";
}

int main()
{
    long long int t;
    int flag1 = 0;
    cin >> t;
    if (t == 737)
        flag1 = 1;
    int n, m, k;
    while (t--)
    {
        solve();
    }
    int count = 0;
    // while (t--)
    // {
    //     count++;
    //     if ((count == 4) && (flag1==1))
    //     {
    //         cin >> n >> m >> k;
    //         vector<int> arr(n);
    //         for (int i = 0; i < k; i++)
    //         {
    //             cin >> arr[i];
    //         }
    //         cout << n << "." << m << "." << k << '.';
    //         for (int i = 0; i < k; i++)
    //         {
    //             cout << arr[i] << '.';
    //         }
    //         cout << "\n";
    //     }
    //     else
    //         solve();
    // }
    return 0;
}
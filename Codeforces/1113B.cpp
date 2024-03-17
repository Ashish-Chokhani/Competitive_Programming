#include <bits/stdc++.h>
using namespace std;

vector<int> factors[101];

void checkPrime()
{
    for (int j = 1; j <= 100; j++)
    {
        for (int i = 1; i * i <= j; i++)
        {
            if (j % i == 0)
            {
                factors[j].push_back(i);
                if ((j / i) != i)
                {
                    factors[j].push_back(j/i);
                }
            }
        }
    }
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } 
    sort(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int o=sum;
    int mini = arr[0];
    for (int i = n - 1; i >= 1; i--)
    {
        for (auto it : factors[arr[i]])
        {
            if(it!=1 && it!=arr[i])
            {
            int x=(arr[i]/it);
            int decrease=arr[i]-x;
            int increase=mini*(it-1);
            sum=min(sum,o+increase-decrease);
            }
        }
    }
    cout<<sum<<"\n";
}

int main()
{
    checkPrime();
    solve();
    return 0;
}

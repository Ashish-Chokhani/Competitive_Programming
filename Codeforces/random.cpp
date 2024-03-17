#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(8);
    cout<<lower_bound(arr.begin(),arr.end(),9)-arr.begin()<<"\n";
    return 0;
}
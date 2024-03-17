#include<bits/stdc++.h>
using namespace std;

bool isEvenTens(int a,int b)
{
    a=a-(a%10);
    b=b-(b%10);
    int x= (b-a)/10;
    return x%2==0;
}

bool isEvenNo(int a)
{
    if((a==1)||(a==2)||(a==4)||(a==8))
    return true;
    else
    return false;
}

bool isEven(int a,int b)
{
    a=a%10;
    b=b%10;
    if((isEvenNo(a) && isEvenNo(b)) || (!isEvenNo(a) && !isEvenNo(b)))
    return true;
    else
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i] % 10 ==5)
        arr[i]=arr[i]+5;
    }
    sort(arr.begin(),arr.end());
    int first=arr[0],flag=1,flag1=0;;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=first)
        flag=0;
        if(arr[i]%10==0)
        flag1=1;
    }
    if(flag==1)
    {
        cout<<"YES\n";
        return;
    }
    if(flag1==1 && flag==0)
    {
        cout<<"NO\n";
        return;
    }

    for(int i=0;i<n-1;i++)
    {
        if((isEven(arr[i],arr[i+1]) && !isEvenTens(arr[i],arr[i+1])) || (!isEven(arr[i],arr[i+1]) && isEvenTens(arr[i],arr[i+1])))
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main()
{
    int t;
    int count=0;
    cin>>t;
    int n;
    vector<int>arr(n);
    while(t--)
    {
        solve();
    }
    return 0;
}
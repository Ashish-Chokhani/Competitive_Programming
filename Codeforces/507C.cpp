#include <bits/stdc++.h>
using namespace std;

string DecToBin(long long int a)
{
    string s;
    vector<long long int>V;
    while(a>0)
    {
        long long int rem=a%2;
        a/=2;
        V.push_back(rem);
    }
    reverse(V.begin(),V.end());
    for(long long int i=0;i<V.size();i++)
    {
        s+=(V[i]+'0');
    }
    return s;
}

bool isLeft(long long int dest, long long int curr)
{
    string d=DecToBin(dest);
    string c=DecToBin(curr);
    long long int l=c.length();
    return (d[l]=='0');
}

long long int findNodes(long long int curLevel,long long int h)
{
    long long int rem=h-curLevel;
    return pow(2,rem)-1;
}

long long int findWays(long long int curr,long long int dest,long long int left,long long int level,long long int h)
{
    if(curr==dest)
    return 0;
    bool l=isLeft(dest,curr);
    if((l) && (left==1))
    {
        return 1+findWays(2*curr,dest,!left,level+1,h);
    }
    if((!l) && (left==0))
    {
        return 1+findWays((2*curr)+1,dest,!left,level+1,h);
    }
    else
    {
        if(left)
        return 1+findNodes(level,h)+findWays((2*curr)+1,dest,1,level+1,h);
        else
        return 1+findNodes(level,h)+findWays((2*curr),dest,0,level+1,h);
    }
}

void solve()
{
    long long int h,n;
    cin>>h>>n;
    cout<<findWays(1,pow(2,h)-1+n,1,0,h)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
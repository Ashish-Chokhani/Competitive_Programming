#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=72;
vector<ll>smallestPrime(MAXN+1);

void  getsmallestPrime(){
    for(ll i=1;i<MAXN;i++){
        smallestPrime[i]=i;
    }
    for(ll i=2;i<MAXN;i++){
        if(smallestPrime[i]==i){
            for(int j=i*i;j<MAXN;j+=i){
                smallestPrime[j]=i;
            }
        }
    }
}

bool canTake(ll n){
    while(n>1){
        ll val=smallestPrime[n];
        if(val>3) return false;
        while(n%val==0){
            n/=val;
        }
    }
    return true;
}

vector<ll>getFactors(ll n){
    vector<ll>factors;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            factors.push_back(i);
            if(n/i !=i) factors.push_back(n/i);
        }
    }
    return factors;
}

bool canPlace(ll mask,ll val,map<ll,ll>&mp){
    if(val==1) return true;
    if(val==2 || val==3) return ((mask>>mp[1])&1) == 1; 
    vector<ll>factors=getFactors(val);
    for(auto it:factors){
        if(!((mask>>mp[it])&1)) return false;
    }
    return true;
}

ll fun(ll i,ll mask,vector<ll>&arr,ll n,map<ll,ll>&mp,vector<vector<ll>>&dp){
    if(i==n) return ((1<<n)-1)==mask;
    if(dp[i][mask]!=-1) return dp[i][mask];
    ll ans=0;
    for(ll ind=0;ind<n;ind++){
        if(!((mask>>ind)&1) && canPlace(mask,arr[ind],mp)){
            ans+=fun(i+1,mask | (1<<ind),arr,n,mp,dp);
        }
    }
    return dp[i][mask]=ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll>arr;
    map<ll,ll>mp;
    for(ll i=1;i<=n;i++){
        if(canTake(i)) {
            arr.push_back(i);
            mp[i]=arr.size()-1;
        }
    }
    ll sz=arr.size();
    vector<vector<ll>>dp(19,vector<ll>((1<<18),-1));
    cout<<fun(0,0,arr,sz,mp,dp);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getsmallestPrime();
    solve();
    return 0;
}

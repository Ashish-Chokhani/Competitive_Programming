#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

vector<ll>primeFactors(ll n,map<ll,ll>&primes){
    vector<ll>prime;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            if(primes[i]) prime.push_back(i);
            if((n/i)!=i && primes[n/i]) prime.push_back(n/i);
        }
    }
    return prime;
}

ll fun(ll i,ll mask,vector<ll>&arr,map<ll,ll>&primes,map<ll,ll>&ind,map<ll,ll>&freq){
    if(i<0) 
    return mask!=0;

    vector<ll>prime=primeFactors(arr[i],primes);
    ll take=0,not_take=0;
    bool canTake=true;
    for(auto it:prime){
        if(mask>>(ind[it])&1)
        canTake=false;
    }
    if(canTake){
        ll newMask=mask;
        for(auto it:prime){
            newMask |= (1<<ind[it]);
        }
        take=freq[arr[i]]*fun(i-1,newMask,arr,primes,ind,freq);
    }
    not_take=fun(i-1,mask,arr,primes,ind,freq);
    return take+not_take;
}
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr;
    map<ll,ll>primes,freq,ind;
    primes[2]=1;
    ind[2]=0;
    primes[3]=1;
    ind[3]=1;
    primes[5]=1;
    ind[5]=2;
    primes[7]=1;
    ind[7]=3;
    primes[11]=1;
    ind[11]=4;
    primes[13]=1;
    ind[13]=5;
    primes[17]=1;
    ind[17]=6;
    primes[19]=1;
    ind[19]=7;
    primes[23]=1;
    ind[23]=8;
    primes[29]=1;
    ind[29]=9;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(!freq[x]){
            bool canPick=true;
            ll temp=x;
            for(auto it:primes){
                ll p=it.first;
                ll cnt=0;
                while(temp%p==0){
                    cnt++;
                    temp/=p;
                }
                if(cnt>1){
                    canPick=false;
                }
            }
            if(canPick){
                arr.push_back(x);
            }
        }
        freq[x]++;
    }
    ll sz=arr.size();
    cout<<fun(sz-1,0,arr,primes,ind,freq)<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll  t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
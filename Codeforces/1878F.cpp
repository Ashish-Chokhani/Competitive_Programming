#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=1e6+2;

vector<ll> primes(1e6 + 1, 0);

void smallestPrime(){
    for (ll i = 1; i <= MAXN; i++){
        primes[i] = i;
    }
    for (ll i = 2; i * i <= MAXN; i++){
        if (primes[i] == i){
            for (ll j = i * i; j <= MAXN; j += i){
                if (primes[j] == j){
                    primes[j] = i;
                }
            }
        }
    }
}

vector<pair<ll,ll>> primeFactors(ll n)
{
    vector<pair<ll,ll>> prime;
    ll num = n;
    while (num > 1){
        ll cnt=1;
        ll p = primes[num];
        num = num / p;
        while ((num % p) == 0)
        {
            num = num / p;
            cnt++;
        }
        prime.push_back({p,cnt});
    }
    sort(prime.begin(),prime.end());
    return prime;
}

vector<pair<ll,ll>> mergeFactors(vector<pair<ll,ll>>&a,vector<pair<ll,ll>>&b){
    vector<pair<ll,ll>>ans;
    ll i=0,j=0,n1=a.size(),n2=b.size();
    while(i<n1 && j<n2){
        if(a[i].first==b[j].first){
            ans.push_back({a[i].first,a[i].second+b[j].second});
            i++;
            j++;
        }
        else if(a[i].first<b[j].first){
            ans.push_back({a[i].first,a[i].second});
            i++;
        }
        else{
            ans.push_back({b[j].first,b[j].second});
            j++;
        }
    }
    while(i<n1){
        ans.push_back({a[i].first,a[i].second});
        i++;
    }
    while(j<n2){
        ans.push_back({b[j].first,b[j].second});
        j++;
    }
    sort(ans.begin(),ans.end());
    return ans;
}

bool check(vector<pair<ll,ll>>&a){
    vector<pair<ll,ll>> cur_factors;
    map<ll,ll>mp;
    for(auto it:a){
        ll num=it.first;
        ll cnt=it.second+1;
        mp[num]=cnt-1;
        vector<pair<ll,ll>> cnt_factors=primeFactors(cnt);
        cur_factors=mergeFactors(cur_factors,cnt_factors);
    }
    for(auto it:cur_factors){
        ll num=it.first;
        ll cnt=it.second;
        if(mp[num]<cnt) return false;
    }
    return true;
}


void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<pair<ll,ll>> factors=primeFactors(n);
    vector<pair<ll,ll>> cur_factors=factors;
    while(q--){
        ll op;
        cin>>op;
        if(op==2){
            cur_factors=factors;
        }
        else{
            ll x;
            cin>>x;
            vector<pair<ll,ll>> x_factors=primeFactors(x);
            cur_factors=mergeFactors(cur_factors,x_factors);
            if(check(cur_factors)){
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt=0;
    smallestPrime();
    while (t--)
    {
        solve();
    }
    return 0;
}
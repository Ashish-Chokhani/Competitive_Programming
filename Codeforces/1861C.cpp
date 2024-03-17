#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    ll n=s.length();
    ll cntPos=0,cntNeg=0;
    vector<ll>decreasing_ind,increasing_ind;
    for(ll i=0;i<n;i++){
        if(s[i]=='+'){
            cntPos++;
            //TO Do
            continue;
        }
        else if(s[i]=='-'){
            cntNeg++;
            if(decreasing_ind.size() && decreasing_ind.back()>(cntPos-cntNeg)){
                decreasing_ind.pop_back();
            }
            if(increasing_ind.size() && increasing_ind.back()>(cntPos-cntNeg)){
                increasing_ind.pop_back();
                increasing_ind.push_back(cntPos-cntNeg);
            }
            continue;
        }
        else{
            if(s[i]=='0' && (cntPos-cntNeg)<=1){
                cout<<"NO\n";
                return;
            }
            else if(s[i]=='1'){
                if(decreasing_ind.size()){
                    cout<<"NO\n";
                    return;
                }
                if(increasing_ind.size() && increasing_ind.back()==(cntPos-cntNeg))
                increasing_ind.pop_back();
                increasing_ind.push_back(cntPos-cntNeg);
            }
            else{
                if(increasing_ind.size() && increasing_ind.back()>=(cntPos-cntNeg)){
                    cout<<"NO\n";
                    return;
                }
                if(decreasing_ind.size() && decreasing_ind.back()==(cntPos-cntNeg))
                decreasing_ind.pop_back();
                decreasing_ind.push_back(cntPos-cntNeg);
            }
        }
    }
    cout<<"YES\n";
}

int main(){
    ll t,cnt=0;
    cin>>t;
    while(t--){
        cnt++;
        solve();
    }
    return 0;
}
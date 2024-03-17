#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>first,second,third;
    for(ll i=0;i<n;i++){
        ll type,val;
        cin>>type>>val;
        if(type==0) first.push_back(val);
        else if(type==1) second.push_back(val);
        else if(type==2) third.push_back(val);
    }
    sort(first.rbegin(),first.rend());
    sort(second.rbegin(),second.rend());
    sort(third.rbegin(),third.rend());
    ll sz=second.size();
    ll sz_first=first.size();
    ll sz_third=third.size();
    ll i=0,j=0,k=0,ans=0,isAvailable=0;
    while(m>0 && i<sz_first && j<sz){
        if(first[i]>=second[j] || m==1){
            ans+=first[i];
            i++;
            m--;
        }
        else{
            if(isAvailable){
                ans+=second[j];
                j++;
                m--;
                isAvailable--;
            }
            else{
                ll val1=first[i];
                if(i+1<sz_first){
                    val1+=first[i+1];
                }
                if(val1<second[j] && k<sz_third){
                    isAvailable=third[k];
                    k++;
                    ans+=second[j];
                    j++;
                    m-=2;
                }
                else{
                    ans+=first[i];
                    i++;
                    m--;
                }
            }
        }
    }
    while(m>0){
        if(i<sz_first){
            ans+=first[i];
            i++;
            m--;
        }
        else if(j<sz){
            if(isAvailable){
                ans+=second[j];
                j++;
                m--;
            }
            else{
                if(k>=sz_third) break;
                else{
                    isAvailable=third[k];
                    k++;
                    m--;
                }
            }
        }
        else {
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

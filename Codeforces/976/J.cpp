#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int k=31,m=1000000007;

int binexp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res*=a;
        n>>=1;
        a*=a;
        a%=m; res%=m;
    }
    return res;
}

void solve(){
    string S; cin>>S;
    int A,B; cin>>A>>B;
    int N=S.length();
    A=N-A; B=N-B;
    vector<int>pre(N);
    int p=1;
    for(int i=0;i<N;i++){
        pre[i]=(i?pre[i-1]:0LL)+(S[i]-'A')*p;
        p*=k;
        pre[i]%=m; p%=m;
    }
    int ans=0,i=0,x=1,cnt=0;
    while(1){
        if(x) i=(i+A)%N;
        else i=(i+B)%N;
        ans++;
        int h1=(pre[N-1]-(i?pre[i-1]:0LL)+m)%m;
        int h2=(binexp(k,i)*pre[N-i-1])%m;
        int h3=(binexp(k,N-i)*(i?pre[i-1]:0LL))%m;
        int h4=(pre[N-1]-pre[N-1-i]+m)%m;
        if(h1==h2 && h3==h4){
            cout<<ans<<"\n";
            return;
        }
        x^=1;
    }    
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
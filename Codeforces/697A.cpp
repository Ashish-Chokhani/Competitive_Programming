#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll determineDir(ll cur_x,ll cur_y,ll newX,ll newY){
    if(newX<cur_x && newY>cur_y)
    return 0;
    if(newX>cur_x && newY>cur_y)
    return 1;
    if(newX>cur_x && newY<cur_y)
    return 2;
    return 3;
}

bool isValid(ll x,ll y,ll n){
    return (x==0 && y==(1LL<<n)) || (x==(1LL<<n) && y==0) || (x==0 && y==0) || (x==(1LL<<n) && y==(1LL<<n));
}


pair<ll,ll> findNext(ll cur_x,ll cur_y,ll dir,ll n){
    if(dir==0){
        return {2*cur_x-(1LL<<n),2*cur_y};
    }
    else if(dir==1){
        return {2*cur_x,2*cur_y};
    }
    else if(dir==2){
        return {2*cur_x,2*cur_y-(1LL<<n)};
    }
    return {2*cur_x-(1LL<<n),2*cur_y-(1LL<<n)};
}

ll whichDir(ll cur_x,ll cur_y,ll n){
    ll newX=2*cur_x-(1LL<<(n-1));
    ll newY=2*cur_y-(1LL<<(n-1));
    if(isValid(newX,newY,n)){
        return determineDir(cur_x,cur_y,1LL<<(n-1),1LL<<(n-1));;
    }
    if(2*cur_x<=(1LL<<n) && 2*cur_y<=(1LL<<n))
    return 1;
    newX=2*cur_x-(1LL<<n);
    newY=2*cur_y;
    if(newX>=0 && newX<=(1LL<<n) && newY<=(1LL<<n))
    return 0;
    newX=2*cur_x-(1LL<<n);
    newY=2*cur_y-(1LL<<n);
    if(newX>=0 && newX<=(1LL<<n) && newY>=0 && newY<=(1LL<<n))
    return 3;
    return 2;
}
  
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll cur_x=x,cur_y=y,ans=0;
    while(cur_x!=(1LL<<(n-1)) || cur_y!=(1LL<<(n-1))){
        ll dir=whichDir(cur_x,cur_y,n);
        pair<ll,ll>next=findNext(cur_x,cur_y,dir,n);
        cur_x=next.first;
        cur_y=next.second;
        ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}
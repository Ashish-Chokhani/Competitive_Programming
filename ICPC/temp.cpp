#include <bits/stdc++.h>
using namespace std;

void solve(int N,vector<array<int,3>>&buildings){
    //Assuming that the buildings are sorted on their endpoints
    int height=0,cur_pos=0;
    vector<array<int,3>>ans;
    vector<int>visited(N,0);
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        visited[i]=1;
        int L=buildings[i][0],R=buildings[i][1],H=buildings[i][2];
        if(L>cur_pos){
            cur_pos=L;
            height=0;
        }
        // L R H
        //In this case, I want to merge the buildings
        if(buildings[i][0]>=cur_pos){
            int j=i+1;
            height=H;
            while(j<N && buildings[j][2]<=height) j++;
            // j pointer will point to the building of next greater height
            if(j<N && buildings[j][0]<=R){
                ans.push_back({buildings[i][0],buildings[i+1][0],height});
                cur_pos=buildings[j][0];
                ans.push_back({{buildings[j][0],buildings[j+1][0],buildings[j][2]}});
                height=max(height,buildings[j][2]);
                visited[j]=1;
            }
            else if(buildings[i][2]<=buildings[j][1]){
                ans.push_back({{buildings[i][2],buildings[j][1],buildings[j][2]}});
            }
            else{
                ans.push_back({buildings[i][0],buildings[i][1],height});
                cur_pos=buildings[i][1];
                height=0;
                if(buildings[i][2]<=buildings[j][1]) ans.push_back({{buildings[i][2],buildings[j][1],buildings[j][2]}});
            }
            
            // cout<<i<<" "<<height<<"\n";
        }
    }
    for(auto [L,R,H]:ans) cout<<L<<" "<<R<<" "<<H<<"\n";
}

int main(){
    int N=5;
    vector<array<int,3>>buildings(N);
    // L R H
    buildings[0]={3,5,2};
    buildings[1]={7,10,4};
    buildings[2]={8,12,6};
    buildings[3]={9,15,10};
    buildings[4]={14,16,8};
    solve(N,buildings);
}
#include<bits/stdc++.h>
using namespace std;
int n,m,mn,mx;
char a[5000010];
int main(){
	cin>>n>>m;
	while(n--){
		int d=m/4,c=0,k=0;
		cin>>a+1;
		for(int i=1;i<m;i++)
			if(a[i]=='1'&&a[i+1]=='1') c++,i++;
		for(int i=1;i<m;i++)
			if(a[i]!='1'||a[i+1]!='1') k++,i++;
		for(int i=1;i<=m;i++) mn+=(a[i]&1),mx+=(a[i]&1);
		mn-=min(c,d);mx-=max(d-k,0);
	}
	cout<<mn<<" "<<mx<<endl;
	return 0;
}
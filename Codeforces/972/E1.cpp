#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
int L,N,M;
int A[1500];
int B[1500][1500],BT[1500][1500];
vector<pair<int,int> >idx[1500*1500];
int R[1501],nR[1501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>L>>N>>M;
		for(int a=0;a<N*M;a++)idx[a].clear();
		for(int i=0;i<L;i++)cin>>A[i],A[i]--;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>B[i][j],B[i][j]--;
		if(N>M)
		{
			for(int i=0;i<N;i++)for(int j=0;j<M;j++)BT[i][j]=B[i][j];
			for(int i=0;i<M;i++)for(int j=0;j<N;j++)B[i][j]=BT[j][i];
			swap(N,M);
		}
		assert(N<=M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			if(idx[B[i][j]].empty()||idx[B[i][j]].back().first<i)idx[B[i][j]].push_back(make_pair(i,j));
			else idx[B[i][j]].back().second=j;
		}
		for(int i=0;i<=N;i++)R[i]=0;
		for(int l=L;l--;)
		{
			for(int i=0;i<=N;i++)nR[i]=0;
			for(auto[i,j]:idx[A[l]])if(R[i+1]<=j+1)nR[i]=j+1;
			R[N]=0;
			for(int i=N;i--;)R[i]=max(nR[i],R[i+1]);
		}
		cout<<(0<R[0]?"T\n":"N\n");
	}
}

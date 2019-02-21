<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
using namespace std;

int card(int a,int b,bool c);
int p[1002];
long long dp[1002][1002];

int main()
{
	int T,N;
	bool t = true;
	
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		
		for(int j=1;j<=N;j++){
			cin>>p[j];
		}
		if(N==1) cout<<p[1]<<"\n";
		else{ 
			if(N%2==0) t = false;
			else t = true;
			for(int l=0;l<N;l++){
				for(int k=1;k+l<=N;k++){
					dp[k][k+l] = card(k,k+l,t);
				}
				t = t ? false : true;
			}
			cout<<dp[1][N]<<"\n";
		}
	}
}

int card(int a,int b,bool c)
{
	if(a==b && true) return p[a];
	else if(b-a==1 && c==true) return max(p[a],p[b]);
	else if(c==false)
		return min(dp[a][b-1],dp[a+1][b]);
	else 
		return max(p[a]+dp[a+1][b], dp[a][b-1]+p[b]);
}
<<<<<<< HEAD
=======
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

<<<<<<< HEAD
#include <iostream> 
using namespace std;
int dp[301][3] = {0};
int p[301] = {0};
 
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>p[i+1];
	
	dp[1][0] = 0;
	dp[1][1] = p[1];
	dp[1][2] = 0;
	
	//ê³„ë‹¨ì˜ ê°œìˆ˜ê°€ 1,2ê°œì¼ ë•Œ 
	if(N<=2){
		cout<<p[N-1] + p[N];
	}
	 
	//ê³„ë‹¨ì´ ì—¬ëŸ¬ê°œì¼ë•Œ 
	else{
	dp[2][1] = p[2];
	dp[2][2] = p[1] + p[2];
		
	for(int i=3;i<=N;i++){
		dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + p[i];
		dp[i][2] = dp[i-1][1] + p[i]; 
	}
	
	cout<<max(dp[N][1],dp[N][2]);
	}

}
=======
/*
#include <iostream> 
using namespace std;
int dp[301][3] = {0};
int p[301] = {0};
 
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>p[i+1];
	
	dp[1][0] = 0;
	dp[1][1] = p[1];
	dp[1][2] = 0;
	
	//°è´ÜÀÇ °³¼ö°¡ 1,2°³ÀÏ ¶§ 
	if(N<=2){
		cout<<p[N-1] + p[N];
	}
	 
	//°è´ÜÀÌ ¿©·¯°³ÀÏ¶§ 
	else{
	dp[2][1] = p[2];
	dp[2][2] = p[1] + p[2];
		
	for(int i=3;i<=N;i++){
		dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + p[i];
		dp[i][2] = dp[i-1][1] + p[i]; 
	}
	
	cout<<max(dp[N][1],dp[N][2]);
	}

}
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

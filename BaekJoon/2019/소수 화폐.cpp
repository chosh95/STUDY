#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int dp[40001];
bool check[40001];
int main()
{
	int N;
	cin>>N;
	for(int i=2;i<=N;i++) check[i] = true;
	check[1] = false;
	for(int i=2;i*i<=N;i++){
		if(!check[i]) continue;
		for(int j=i+i;j<=N;j+=i){
			check[j] = false;
		}
	}	
	for(int i=2;i<=N;i++)
		if(check[i])
			v.push_back(i);
			
	dp[0]=1;
	for(int i=0;i<v.size();i++){
		for(int j=v[i];j<=N;j++){
			dp[j] += (dp[j-v[i]]%123456789);
			dp[j]%=123456789;
		}
	}
	cout<<dp[N];
}

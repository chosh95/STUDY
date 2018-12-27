/*
#include <iostream>
using namespace std;
int p[501][501];
void Equal(int N,int k);
int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++) p[i][i] = 1;
	cout<<"a1";
	p[1][N] = p[N][1] = 1;
	Equal(N,1);
	cout<<" a1";
}

void Equal(int N,int k)
{
	for(int i=1;i<=N;i++){
		if(p[k][i]!=1){
			cout<<" a"<<i;
			p[k][i] = p[i][k] = 1;
			Equal(N,i);
		}
		else continue;
	}
}
*/

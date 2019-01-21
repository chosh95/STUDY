#include <iostream>
using namespace std;
void shortcase(int *p,int L,int N);
void longcase(int *p,int L,int N);
int main()
{
	int T; //테스트 케이스 
	cin>>T;
	for(int i=0;i<T;i++){
		int L,N; //막대 길이랑 개미의 수
		cin>>L>>N;
		int *p = new int[N+2];
		for(int j=1;j<=N;j++) cin>>p[j];
		shortcase(p,L,N);
		longcase(p,L,N); 
		delete []p;
	}
	return 0;
}

void shortcase(int *p,int L,int N)
{
	int max=0;
	for(int i=1;i<=N;i++){
		if(p[i]>L/2){
			if((L - p[i])>max) max = L-p[i];
			else continue;
		} 
		else{
			if(p[i]>max) max = p[i];
			else continue;
		}
	}
	if(max>L/2) max = L/2;
	cout<<max<<" ";
}
void longcase(int *p,int L,int N)
{
	int max = 0;
	for(int i=1;i<=N;i++){
		if(p[i]>L/2){
			if(p[i]>max) max = p[i];
			else continue;
		}
		else{
			if(L-p[i]>max) max = L-p[i];
			else continue;
		}
	}
	cout<<max<<endl;
}

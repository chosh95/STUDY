/*
#include <iostream>
using namespace std;
int main()
{
	int N,t=0,i=1;
	cin>>N;
	if(N%5==0){
		cout<<N/5;
		t=1;
	}
	else{
		for(i=1;N>0;i++){
			N=N-3;
			if(N%5==0 && N>=5){
				cout<<i+N/5;
				t=1;
				break;
			}
		}   
	}
	if(N==0) cout<<i-1;
	else if(t!=1) cout<<-1;
}
*/

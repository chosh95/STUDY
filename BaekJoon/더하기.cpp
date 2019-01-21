#include <iostream>
using namespace std;
int C(int N,int count);
int main()
{
	int N;
	cin>>N;
	int count=1;
	count = C(N,count);
	cout<<count;
}

int C(int N,int count)
{
	if(N==1) return count;
	if(N%2==0){
		C(N/2,++count);
	}
	else{
		C(N*3+1,++count);
	}
}

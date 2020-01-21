#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A,B;
	cin>>A>>B;
	int a[3];
	int b[3];
	for(int i=0;i<3;i++){
		a[2-i] = A[i];
		b[2-i] = B[i];
	}
	if(a[0]>b[0]){
		for(int i=0;i<3;i++){
			cout<<(a[i]-'0');
		}
	}
	else if(a[0]==b[0] && a[1]>b[1]){
		for(int i=0;i<3;i++){
			cout<<(a[i]-'0');
		}
	}
	else if(a[0]==b[0] && a[1]==b[1] && a[2]>b[2]){
		for(int i=0;i<3;i++){
			cout<<(a[i]-'0');
		}
	}
	else{
		for(int i=0;i<3;i++){
			cout<<(b[i]-'0');
		}
	}
}

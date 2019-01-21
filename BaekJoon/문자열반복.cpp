#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T,R;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>R;
		string S;
		cin>>S;
		for(int j=0;j<S.length();j++){
			for(int k=0;k<R;k++){
				cout<<S[j];
			}
		}
		cout<<endl;
	}
}

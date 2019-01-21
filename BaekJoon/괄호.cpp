#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		string S;
		cin>>S;
		int res=0;
		bool t=true;
		for(int j=0;j<S.size();j++){
			if(S[j]=='(') res++;
			else res--;
			
			if(res<0){
				t=false;
				break;
			}
		}
		
		if(t && res == 0) cout<<"YES"<<endl;
		else if(!t || res>0) cout<<"NO"<<endl;
	} 
	return 0;
}

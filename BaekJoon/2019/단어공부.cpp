#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int p[27];
int main()
{
	string S;
	cin>>S;
	for(int i=0;i<S.length();i++){
		for(int j=0;j<26;j++){
			if(S[i]=='a'+j || S[i]=='A'+j) p[j]++;
		}
	}
	int index=0,max = 0;
	bool tmp = false;
	for(int i=0;i<=26;i++){
		if(p[i]>max){
			max = p[i];
			tmp = false;
			index=i;
		}
		else if(p[i]==max){
			tmp = true;
		}
	}
	if(tmp) cout<<"?";
	else cout<<(char)('A'+index);
}

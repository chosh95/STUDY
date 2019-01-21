#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	cin>>S;
	int p[26];
	int pos;
	
	for(int i=0;i<26;i++) p[i]=-1;
	
	for(int i=0;i<S.size();i++){
		pos = S[i]-'a';
		if(p[pos]==-1) p[pos] = i;		
	}
	
	for(int i=0;i<26;i++){
		cout<<p[i]<<' ';
	}
}

/*#include <iostream>
#include <string>
using namespace std; 

int main()
{
	int T,res;
	cin>>T;
	int p[10000][81];
	
	for(int i=1;i<=T;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='X') p[i][j]==0;
			else if(s[j]=='O' && p[i][j-1]!=0) p[i][j] = p[i][j-1]+1;
			else p[i][j] = 1;
			res+=p[i][j];
		}
		cout<<res<<endl;
		res=0;		
	}
}*/

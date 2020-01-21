#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	char p[52][52];
	for(int i=1;i<=N;i++){
		scanf("%s",p[i]);
	}
	if(N==1){
		for(int i=0;i<=51;i++){
			if(p[1][i]==NULL) break;
			else cout<<p[1][i];
		}
	}
	else{
		for(int i=1;i<N;i++){
			for(int j=0;j<51;j++){
				if(p[i][j]==NULL || p[i][j]=='/n') break;
				if(N==2){
					if(p[i][j]==p[i+1][j]) p[0][j] = p[i][j];
					else p[0][j] = '?';
				}  
				else if(i==1) p[0][j] = p[1][j];
				else if(p[i][j]==p[i+1][j] && p[i][j]==p[0][j]) p[0][j] = p[i][j];
				else p[0][j] = '?';
			}
		}
		for(int i=0;i<=51;i++){
			if(p[0][i]==NULL) break;
			else cout<<p[0][i];
		}
	}
}

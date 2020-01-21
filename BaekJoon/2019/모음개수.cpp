#include <iostream> 
#include <string>
using namespace std;

int main()
{
	string arr;
	int res[256] = {0};
	int a=1,j=0;
		
	while(a){
		getline(cin,arr);
		for(int i=0;i<256;i++){
			if(arr[i]=='#'){a=0; res[j]=-1; break;}
			if(arr[i] == 'a' || arr[i] == 'A' || arr[i] == 'e' || arr[i] == 'E'
			|| arr[i] == 'i' || arr[i] == 'I' ||  arr[i] == 'o'
			|| arr[i] == 'O' || arr[i] == 'u' || arr[i] == 'U') res[j]++;
			if(arr[i]=='\0') {break; }
		}
		j++;
	}
	
	for(int i=0;i<256;i++){
		if(res[i]==-1) break;
		cout<<res[i]<<endl;
	}
	return 0;
}

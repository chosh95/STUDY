#include <iostream>
#include <string>
using namespace std;

int main()
{
	string c;
	bool a = true; 
	cin>>c;
	while(a){
		for(int i=0;i<=101;i++){
			if(c[i]){
				if((i+1)%10==0 && i!=0) cout<<c[i]<<endl;
				else	cout<<c[i];
			}
			else{
				a=false;
				cout<<endl;
				break;
			}
		}
	}
}
*/

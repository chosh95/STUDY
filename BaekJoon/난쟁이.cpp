<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream> 
#include <algorithm>
using namespace std;
int p[10] = {0};

int main()
{
	int sum=0;
	for(int i=1;i<10;i++){
		cin>>p[i];
		sum += p[i];
	}
	int t=0,a=0,b=0;
	for(int l=1;l<9;l++){
		for(int k=l+1;k<10;k++){
			if((sum-(p[l]+p[k]))==100){
				a = p[l];
				b = p[k];
				sort(p+1,p+10);
				for(int i=1;i<10;i++){
					if(p[i] == a || p[i] == b) continue;
					else cout<<p[i]<<"\n";
				}
				t=1;
				break;	
			}
			else continue;
		}
		if(t==1) break;
	}
	return 0;
}
<<<<<<< HEAD
=======
*/

>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

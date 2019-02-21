<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
using namespace std;
int p[1004];
int q[1004];
int main()
{
<<<<<<< HEAD
	int N,t=0,c=0; //c=0:Â³Â»Â¸Â®Â¸Â· c=1:Â¿Ã€Â¸Â£Â¸Â· c=2:Ã†Ã²ÃÃ¶ 
=======
	int N,t=0,c=0; //c=0:³»¸®¸· c=1:¿À¸£¸· c=2:ÆòÁö 
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
	cin>>N;
	if(N==0) cout<<0;
	else{
	for(int i=0;i<N;i++) cin>>p[i];
	p[N] = 0;
	
	if(p[0]>p[1]) c=0;
	else if(p[0]<p[1]) {c=1; q[t++] = p[0];}
	else {c=2;}
	for(int i=0;i<N;i++){
		if(p[i]<p[i+1] && c==0){q[t++]=p[i]; c=1;}
		else if(p[i]>p[i+1] && c==1){q[t++]=p[i]; c=0;}
		else if(p[i]==p[i+1] && c==1){q[t++]=p[i]; c=2;}
		else if(c==2){
			if(p[i]>p[i+1]) c=0;
			else if(p[i]<p[i+1]) {q[t++]=p[i]; c=1;}
			else if(p[i]==p[i+1]) c=2; 
		}  
	}
	int max=0;
	for(int i=0;i<N;i+=2){
		if(q[i+1]==q[i] && q[i]==0) break;
		if(q[i+1]-q[i]>max) max = q[i+1]-q[i];
	}
	if(q[1]==0) max = 0;
	cout<<max;
	}
}
<<<<<<< HEAD
=======
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

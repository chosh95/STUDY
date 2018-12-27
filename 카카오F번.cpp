/*
#include <iostream>
using namespace std;

struct point{
	int x;
	int y;
};

int main()
{
	int N;
	cin>>N;
	point *p = new point[N+1];
	for(int i=0;i<=N;i++){
		cin>>p[i].x>>p[i].y;
	}
	int min = p[i].y
	for(int i=1;i<=N;i++){
		if(p[i].y<min) min = p[i].y;
	}
	int max=0,tmp,t;
	for(int i=1;i<=N;i++){
		if(p[i-1].y==p[i].y){
			tmp = (p[i].x-p[i-1].x)*(p[i.y]-min); 
			if(tmp>max){
				 max = tmp;
				 t = i;
			}
		}
	}
	int res = 0;
	res += (p[t].x-p[t-1].x)*p[t].y;
	if(t>=2) 	
	
}
*/

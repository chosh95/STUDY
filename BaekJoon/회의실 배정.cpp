<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
#include <algorithm>
using namespace std;
struct time{
	int start;
	int end;
};

bool cmp_time(time a,time b);

int main()
{
<<<<<<< HEAD
	int N;	//회의의 수 
=======
	int N;	//ȸ���� �� 
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
	cin>>N;
	time a[N+1]; 
	for(int i=1;i<=N;i++){
		cin>>a[i].start;
		cin>>a[i].end;
	}
	sort(a+1,a+N+1,cmp_time);
	
	//for(int i=1;i<=N;i++) cout<<a[i].start<<" "<<a[i].end<<endl;
	
<<<<<<< HEAD
	int min_end = a[1].end; // 현재 가장 빨리 끝나느 회의 시간 기록용 
	int count = 1;	// 최대 회의 수 기록용 
=======
	int min_end = a[1].end; // ���� ���� ���� ������ ȸ�� �ð� ��Ͽ� 
	int count = 1;	// �ִ� ȸ�� �� ��Ͽ� 
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
	for(int i=2;i<=N;i++){
		if(a[i].start >= min_end){ 
			min_end = a[i].end;
			++count;
		}
	}
	cout<<count;
}

<<<<<<< HEAD
bool cmp_time(time a,time b) //구조체 time 시간 비교  
{
	if(a.end<b.end) return true; 
	else if(a.end==b.end) return a.start<b.start; //끝나는 시간이 같으면 
										//일찍 시작하는걸 앞으로 정렬 
	else return false;
}
=======
bool cmp_time(time a,time b) //����ü time �ð� ��  
{
	if(a.end<b.end) return true; 
	else if(a.end==b.end) return a.start<b.start; //������ �ð��� ������ 
										//���� �����ϴ°� ������ ���� 
	else return false;
}
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

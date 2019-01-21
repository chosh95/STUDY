#include <iostream>
using namespace std;
int arr[302] = {0}; // arr[i]에 i번째 계단의 점수, arr[0]은 점수의 최대값 저장용  
void stair(int currentPos, int status, int finalPos);
bool IsNextStep(int currentPos,int finalPos);
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i+1];
	
	stair(0,0,N);
	cout<<arr[0];
	return 0;	
}

//currentPos : 지금 밟고 있는 계단 - 값을 이미 arr[0]에 더한 상태 
//finalPos : 마지막 계단
//status : 0이면 시작, 1이면 저번 계단을 안 밟고 이번 계단에 오른거, 2면 저번 계단과 이번 계단을 연속으로 밟은 상태 

void stair(int currentPos, int status,int finalPos)
{
	if(currentPos == finalPos-1){
		 arr[0] += arr[finalPos];
	}
	else if(currentPos==finalPos-2){
		if(status==0) arr[0] = arr[currentPos+1] + arr[currentPos+2]; 
		else if(status==1 || status==2) arr[0] += arr[finalPos];
	}
	
	else if(status==0){
		if(IsNextStep(currentPos+1,finalPos) && IsNextStep(currentPos+2,finalPos)){ 
			arr[0] += arr[currentPos+2];
			stair(currentPos+2,1,finalPos);
		}
		else{
			arr[0] += arr[currentPos+1];
			stair(currentPos+1,1,finalPos);
		}
	}
	else if(status==1){
		if(IsNextStep(currentPos,finalPos)){
			arr[0] += arr[currentPos+1];
			stair(currentPos+1,status+1,finalPos);
		}
		else{
			arr[0] += arr[currentPos+2];
			stair(currentPos+2,1,finalPos);
		}
	}
	else if(status==2){
		arr[0] += arr[currentPos+2];
		stair(currentPos+2,1,finalPos);
	}
}

bool IsNextStep(int currentPos,int finalPos)
{
	if(currentPos==finalPos-1) return true;
	else if(currentPos==finalPos-2) return false;
	else if(currentPos==finalPos-3){
		if(arr[currentPos+1]<arr[currentPos+2]) return false;
		else return true; 
	}
	else if(IsNextStep(currentPos+1,finalPos) && IsNextStep(currentPos+2,finalPos)) return false;
	else if(!IsNextStep(currentPos+1,finalPos) && IsNextStep(currentPos+2,finalPos)) return true;
	else if(IsNextStep(currentPos+1,finalPos) && arr[currentPos]<arr[currentPos+1]) return true;
	else return false;
}

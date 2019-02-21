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
	int N;	//íšŒì˜ì˜ ìˆ˜ 
=======
	int N;	//È¸ÀÇÀÇ ¼ö 
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
	int min_end = a[1].end; // í˜„ìž¬ ê°€ìž¥ ë¹¨ë¦¬ ëë‚˜ëŠ íšŒì˜ ì‹œê°„ ê¸°ë¡ìš© 
	int count = 1;	// ìµœëŒ€ íšŒì˜ ìˆ˜ ê¸°ë¡ìš© 
=======
	int min_end = a[1].end; // ÇöÀç °¡Àå »¡¸® ³¡³ª´À È¸ÀÇ ½Ã°£ ±â·Ï¿ë 
	int count = 1;	// ÃÖ´ë È¸ÀÇ ¼ö ±â·Ï¿ë 
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
bool cmp_time(time a,time b) //êµ¬ì¡°ì²´ time ì‹œê°„ ë¹„êµ  
{
	if(a.end<b.end) return true; 
	else if(a.end==b.end) return a.start<b.start; //ëë‚˜ëŠ” ì‹œê°„ì´ ê°™ìœ¼ë©´ 
										//ì¼ì° ì‹œìž‘í•˜ëŠ”ê±¸ ì•žìœ¼ë¡œ ì •ë ¬ 
	else return false;
}
=======
bool cmp_time(time a,time b) //±¸Á¶Ã¼ time ½Ã°£ ºñ±³  
{
	if(a.end<b.end) return true; 
	else if(a.end==b.end) return a.start<b.start; //³¡³ª´Â ½Ã°£ÀÌ °°À¸¸é 
										//ÀÏÂï ½ÃÀÛÇÏ´Â°É ¾ÕÀ¸·Î Á¤·Ä 
	else return false;
}
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

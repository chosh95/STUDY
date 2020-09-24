#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int res = 0, cnt = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int cur = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) cur++;
        if (res < cur) {
            res = cur;
            if (cnt != 0) answer.push_back(cnt);
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    if(cnt !=0)
        answer.push_back(cnt);
    return answer;
}

int main()
{
    vector<int> res = solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
    for (int it : res) {
        cout << it << " ";
    }
}
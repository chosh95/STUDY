#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> origin, tmp;
    for (int i = 0; i < gems.size(); i++)
        origin.insert({gems[i], 1});
    
    int minCnt = 987654321, startIdx = 0, endIdx = 0;
    int startTmp = 0;
    for (int i = 0; i < gems.size(); i++) {
        tmp[gems[i]]++;
        while(tmp.size() == origin.size()) {
            if (minCnt > i - startTmp) {
                minCnt = i - startTmp;
                startIdx = startTmp+1;
                endIdx = i+1;
            }
            if (tmp[gems[startTmp]] == 1) tmp.erase(gems[startTmp]);
            else tmp[gems[startTmp]]--;
            startTmp++;
        }
    }

    answer.push_back(startIdx);
    answer.push_back(endIdx);
    return answer;
}

int main()
{
    vector<int> res = solution({ "AA","AB","AC","AB","AA" });
    for (int i : res) {
        cout << i << " ";
    }
}
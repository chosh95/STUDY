#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> m;

    for (int i = 0; i < numbers.size(); i++) 
        for (int j = i + 1; j < numbers.size(); j++) 
            m[numbers[i] + numbers[j]] = 1;

    for (auto it : m) 
        answer.push_back(it.first);
    
    sort(answer.begin(), answer.end());

    return answer;
}


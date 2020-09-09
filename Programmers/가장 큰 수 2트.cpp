#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string strA, string strB) {
    if (strA + strB > strB + strA) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        answer += v[i];
    if (answer[0] == '0') answer = "0";
    return answer;
}

int main()
{
    cout << solution({ 0, 0, 0 });
}
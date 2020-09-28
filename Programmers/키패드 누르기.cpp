#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
pair<int, int> pos[13] = { {4,2}, {1,1},{1,2},{1,3},
    {2,1},{2,2},{2,3},
    {3,1},{3,2},{3,3},
    {4,1},{4,3} };

string dist(int left, int right, int target, string hand) {
    int leftCost = abs(pos[target].first - pos[left].first) + abs(pos[target].second - pos[left].second);
    int rightCost = abs(pos[target].first - pos[right].first) + abs(pos[target].second - pos[right].second);
    if (leftCost == rightCost) return hand;
    if (leftCost > rightCost) return "right";
    return "left";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int curLeft= 10, curRight = 11;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            curLeft = numbers[i];
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            curRight = numbers[i];
            answer += "R";
        }
        else {
            string cur = dist(curLeft, curRight, numbers[i], hand);
            if (cur == "left") {
                curLeft = numbers[i];
                answer += "L";
            }
            else {
                curRight = numbers[i];
                answer += "R";
            }

        }
    }

    return answer;
}

int main()
{
    cout << solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
}
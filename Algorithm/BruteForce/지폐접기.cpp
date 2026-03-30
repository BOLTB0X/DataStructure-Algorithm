// https://school.programmers.co.kr/learn/courses/30/lessons/340199
#include <string>
#include <vector>

using namespace std;

bool isPossible(int a1, int b1, int a2, int b2)
{
    if (a1 >= a2 && b1 >= b2)
        return true;
    return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while (true)
    {
        if (isPossible(wallet[0], wallet[1], bill[0], bill[1])) break;
        if (isPossible(wallet[0], wallet[1], bill[1], bill[0])) break;
        
        if (bill[0] > bill[1]) 
            bill[0] /= 2;
        else bill[1] /= 2;
        answer++;
    }
    return answer;
}
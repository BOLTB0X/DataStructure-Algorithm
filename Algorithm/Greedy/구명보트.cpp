#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int currentIndex = 0;
    
    sort(people.begin(), people.end());
    
    while (currentIndex < people.size()) {
        int back = people.back();
        people.pop_back();
        
        if (people[currentIndex] + back <= limit)
            currentIndex++;
        
        answer++;
    }
    
    return answer;
}
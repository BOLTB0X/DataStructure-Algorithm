#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> umap;
    
    for (const string par: participant)
        umap[par]++;
    
    for (const string com: completion)
        umap[com]--;
    
    for (auto pair : umap) {
        if (pair.second)
            answer = pair.first;
    }
    
    return answer;
}
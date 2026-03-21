// https://school.programmers.co.kr/learn/courses/30/lessons/340213
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int convertSeconds(string t) {
    string m = t.substr(0, 2);
    string s = t.substr(3);
    
    return stoi(m) * 60 + stoi(s);
}

string convertSS(int t) {
    string ret = "";
    string a = to_string(t/60);
    if (a.size() == 1) a = "0" + a;
    
    string b = to_string(t%60);
    if (b.size() == 1) b = "0" + b;
    return a + ":" + b;
}

int move(int s, int v, int total) {
    s += v;
    if (s <= 10) return 0;
    else if (s >= total) return total;
    return s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int videoLen = convertSeconds(video_len);
    int position = convertSeconds(pos);
    int opStart = convertSeconds(op_start);
    int opEnd = convertSeconds(op_end);
    
    if (position >= opStart && position <= opEnd)
        position = opEnd;
    
    for (const string cmd: commands)
    {
        if (cmd == "prev")
        {
            position -= 10;
            if (position < 0)
                position = 0;
        }
        else if (cmd == "next")
        {
            position += 10;
            if (position > videoLen)
                position = videoLen;
        }
        
        if (position >= opStart && position <= opEnd)
            position = opEnd;
    }
    
    answer = convertSS(position);
    return answer;
}
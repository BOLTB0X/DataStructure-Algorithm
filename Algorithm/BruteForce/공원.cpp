// https://school.programmers.co.kr/learn/courses/30/lessons/340198
#include <string>
#include <vector>

using namespace std;

bool check(const vector<vector<string>> park, const string alp, int cx, int cy, int mat)
{
    for (int i = cx; i < cx + mat; ++i)
    {
        for (int j = cy; j < cy + mat; ++j)
        {
            if (park[i][j] != alp) return false;
        }
    }
    
    return true;
} // check

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int n = park.size(), m = park[0].size();
    
    for (const int mat: mats)
    {
        for (int i = 0; i <= n - mat; ++i)
        {
            for (int j = 0; j <= m - mat; ++j)
            {
                if (park[i][j] != "-1") continue;
                
                if (check(park, park[i][j], i, j, mat))
                    answer = max(mat, answer);
            }
        }
    }
    return answer == 0 ? -1 : answer;
} // solution
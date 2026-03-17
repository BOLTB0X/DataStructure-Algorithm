// https://school.programmers.co.kr/learn/courses/30/lessons/86052
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<int>> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    vector<vector<vector<bool>>> visited(grid.size(),vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));
    
    int row = grid.size(), col = grid[0].size();
    
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            for(int k = 0; k < 4; ++k)
            {
                int cnt = 0;
                int cx = i, cy = j, cd = k;
                
                while (visited[cx][cy][cd] == false)
                {
                    visited[cx][cy][cd] = true;
                    cnt++;
                    
                    if (grid[cx][cy] == 'L')
                        cd = (cd + 3) % 4;
                    else if (grid[cx][cy] == 'R')
                        cd = (cd + 1) % 4;
                    
                    cx = (cx + dir[cd][0] + row) % row;
                    cy = (cy + dir[cd][1] + col) % col;
                    
                    
                } // while
                if (cnt) answer.push_back(cnt);
            } // for k
        } // for j
    } // for i
    
    sort(answer.begin(), answer.end());
    return answer;
}
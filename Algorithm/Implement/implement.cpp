#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v)
{
    for (const int ele: v)
        cout << ele << ' ';
    cout << '\n';
}

void print_Matrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); ++i)
    {
        for (const int ele : mat[i])
            cout << ele << ' ';
        cout << '\n';
    }
}

// 시계
void rotate_Right(vector<int>& v)
{
    int last = v.back();
    v.pop_back();
    v.insert(v.begin(), last);
}

// 반시계
void rotate_Left(vector<int>& v)
{
    int first = v.front();
    v.erase(v.begin());
    v.push_back(first);
}

// 정방행렬 시계 방향 회전
vector<vector<int>> rotate_90(const vector<vector<int>> mat)
{
    int n = mat.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rotated[j][n - 1 - i] = mat[i][j];

    return rotated;
}

// 정방행렬 반시계 방향 회전
vector<vector<int>> rotate_minor_90(const vector<vector<int>> mat)
{
    int n = mat.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rotated[n - 1 - j][i] = mat[i][j];

    return rotated;
}

// 90도 시계: r X c -> c X r
// 90도 반시계: r X c -> c X r
// 180도: r X c -> r X c

// rXc 행렬 회전 90
vector<vector<int>> rotate_90_2(const vector<vector<int>> mat)
{
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>> result(c, vector<int>(r));
    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[j][r - 1 - i] = mat[i][j];
    
    return result;
}

// rXc행렬 반시계 방향 회전
vector<vector<int>> rotate_minor_90_2(const vector<vector<int>> mat)
{
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>> result(c, vector<int>(r));
    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[c - 1 - j][i] = mat[i][j];
    
    return result;
}

// 180도 회전
vector<vector<int>> rotate_180(const vector<vector<int>> mat) {
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>> result(r, vector<int>(c));
    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[r - 1 - i][c - 1 - j] = mat[i][j];
    
    return result;
}

int main(void)
{
    vector<int> v = {1, 2, 3, 4, 5};
    print_vector(v);

    //rotate_Right(v);
    rotate_Left(v);

    print_vector(v);

    return 0;
}
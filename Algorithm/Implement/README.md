# Implement

> 구현 관련 코드들 정리

## Rotate in 1차원

1. **시계방향 (= 오른쪽)**

   ```cpp
   // 시계
   void rotate_Right(vector<int>& v)
   {
       int last = v.back();
       v.pop_back();
       v.insert(v.begin(), last);
   }
   ```

   ---

2. **반시계방향 (= 왼쪽)**

   ```cpp
   void rotate_Left(vector<int>& v)
   {
       int first = v.front();
       v.erase(v.begin());
       v.push_back(first);
   }
   ```

   ---

## Rotate in 2차원

180도 : `r` X `c` -> `r` X `c`

1. **정방행렬 시계 방향 회전**

   ```cpp
   vector<vector<int>> rotate_90(const vector<vector<int>> mat)
   {
       int n = mat.size();
       vector<vector<int>> rotated(n, vector<int>(n, 0));

       for (int i = 0; i < n; ++i)
           for (int j = 0; j < n; ++j)
               rotated[j][n - 1 - i] = mat[i][j];

       return rotated;
   }
   ```

   ---

2. **정방행렬 반시계 방향 회전**

   ```cpp
   vector<vector<int>> rotate_minor_90(const vector<vector<int>> mat)
   {
       int n = mat.size();
       vector<vector<int>> rotated(n, vector<int>(n, 0));

       for (int i = 0; i < n; ++i)
           for (int j = 0; j < n; ++j)
               rotated[n - 1 - j][i] = mat[i][j];

       return rotated;
   }

   ---

3. **`r` X `c` 행렬 회전 90**

   90도 : `r` X `c` -> `c` X `r`

   ```cpp
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
   ```

   ---

4. **`r` X `c` 행렬 반시계 방향 회전**

   90도 : `r` X `c` -> `c` X `r`

   ```cpp
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
   ```

   ---

5. **180도 회전**

   180도 : `r` X `c` -> `r` X `c`


   ```cpp
   vector<vector<int>> rotate_180(const vector<vector<int>> mat) {
       int r = mat.size();
       int c = mat[0].size();
       vector<vector<int>> result(r, vector<int>(c));
    
       for (int i = 0; i < r; ++i)
           for (int j = 0; j < c; ++j)
               result[r - 1 - i][c - 1 - j] = mat[i][j];
    
       return result;
   }
   ```
# Prefix Sum / Cumulative Sum

> 배열의 일부 구간 합을 빠르게 계산하기 위한 기법

## 1차원 누적합 (Prefix Sum)

- **기본 개념**

  배열 의 특정 인덱스까지의 합을 저장한 배열을 생성해 이용하는 것

  ```
  prefixSum[i] = arr[0] + arr[1] + ... + arr[i]
  ```

  이러면, 구간 `[L, R]` 의 합을 `O(1)` 만에 구하는 게 가능

  ```
  S(L,R) = prefixSum[R + 1] - prefixSum[L]

  S(L,R) = prefixSum[R] - prefixSum[L-1]
  ```

  (단, `L = 0` 이면 `prefixSum[L - 1]` 을 0으로 처리)
  <br/>

- **코드**

  ```swift
  var prefixSum = [Int](repeating: 0, count: N + 1)

  for i in 0..<N {
     prefixSum[i + 1] = prefixSum[i] + arr[i]
  }

  let L = 1, R = 3
  print(prefixSum[R + 1] - prefixSum[L]) // 7
  ```

  ```swift
  for i in 0..<N {
   prefixSum[i] = prefixSum[i - 1] + arr[i]
  }

  let L = 1, R = 3
  print(prefixSum[R] - prefixSum[L - 1]) // 7
  ```

## 2차원 누적합 (2D Prefix Sum)

- **기본 개념**
  (0,0)부터 (i,j)까지의 영역 합을 의미

  ```swift
  prefixSum[i][j] = arr[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]
  // (마지막 - prefixSum[i-1][j-1]는 중복 더해진 부분 제거용)
  ```

  임의의 직사각형 구간 (x1, y1) ~ (x2, y2)의 합은

  ```
  S(x1,y1,x2,y2) = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1]
  ```

   <br/>

- **코드**

  ```swift
  // 누적합 배열
  var prefixSum = [[Int]](repeating: [Int](repeating: 0, count: K + 1), count: M + 1)

  // 누적합 계산
  for i in 1...M {
      for j in 1...K {
          prefixSum[i][j] = arr2[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]
      }
  }

  // 예제: 구간 합 (1,1) ~ (2,2) => arr[1][1] + arr[1][2] + arr[2][1] + arr[2][2]
  let x1 = 1, y1 = 1, x2 = 2, y2 = 2

  let result = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1]

  print(result) // 5 + 6 + 8 + 9 = 28

  ```

  <br/>

## 차분 배열 기법(Difference Array Technique)

> 주로 누적합과 함께 사용되며, 배열의 연속적인 부분에 대한 업데이트를 빠르게 수행할 수 있도록 해준다

1. **1차원**

   - 특정 구간 `[s, e]` 에 `+val`을 한 번에 반영하기 위해 이용
     - `arr[s] += val` (시작점 증가)
     - `arr[e+1] -= val` (끝나는 다음 위치에서 감소)
       <br/>
   - 마지막에 누적합을 계산하여 반영된 변화를 적용

   - 예제

     ```swift
     arr = [0, 0, 0, 0, 0] , s = 1, e = 3
     ```

     ```swift
     // 1
     arr[s] += 5
     arr[e + 1] -= 5  // e+1 위치에서 감소
     ```

     ```swift
     // 2
     [0, +5, 0, 0, -5]
     ```

     ```swift
     // 3
     for i in 1..<arr.count {
        arr[i] += arr[i-1]
     }

     // [0, 5, 5, 5, 0]
     ```

     <br/>

2. **2차원**

   - `(x1, y1)` ~ `(x2, y2)` 직사각형 영역에 적용

     | 좌표         | 역할                        |
     | ------------ | --------------------------- |
     | (x1, y1)     | +val (왼쪽 상단에서 증가)   |
     | (x1, y2+1)   | -val (오른쪽 상단에서 감소) |
     | (x2+1, y1)   | -val (왼쪽 하단에서 감소)   |
     | (x2+1, y2+1) | +val (보정)                 |

      <br/>

   - 예제 : `(1,1)` ~ `(3,3)` 에 `+5` 적용

     ```swift
     // 1
     prefixSum[1][1] += 5     // 좌상단 시작점
     prefixSum[1][3+1] -= 5   // 우상단 다음 열 감소
     prefixSum[3+1][1] -= 5   // 좌하단 다음 행 감소
     prefixSum[3+1][3+1] += 5 // 두 번 빠진 부분 보정
     ```

     ```
     // 1 결과
     0  0  0  0  0
     0 +5  0  0  -5
     0  0  0  0   0
     0  0  0  0   0
     0 -5  0  0  +5
     ```

     ```swift
     // 2 가로 방향 누적합 적용
     for i in board.indices {
         for j in board[i].indices {
             prefixSum[i][j+1] = prefixSum[i][j]
         }
     }
     ```

     ```swift
     // 2
     0  0  0  0  0
     0 +5  +5  +5  0
     0  0  0   0   0
     0  0  0   0   0
     0 -5 -5  -5  0
     ```

     ```swift
     // 3 세로 방향 누적합 적용
     for j in board[0].indices {
         for i in board.indices {
             prefixSum[i+1][j] = prefixSum[i][j]
         }
     }
     ```

     ```swift
     // 3
     0  0   0   0  0
     0 +5  +5  +5  0
     0 +5  +5  +5  0
     0 +5  +5  +5  0
     0  0   0   0  0
     ```

## 연습문제

0. [BOJ-11659(구간 합 구하기 4)](https://www.acmicpc.net/problem/11659) , [BOJ-11660(구간 합 구하기 5)](https://www.acmicpc.net/problem/11660)

1. [BOJ-29700(우당탕탕 영화예매)](https://www.acmicpc.net/problem/29700)

2. [BOJ-20438(출석체크)](https://www.acmicpc.net/problem/20438)

3. [BOJ-21318(피아노 체조)](https://www.acmicpc.net/problem/21318)

4. [BOJ-16507(어두운 건 무서워)](https://www.acmicpc.net/problem/16507)

5. [BOJ-19951(태상이의 훈련소 생활)](https://www.acmicpc.net/problem/19951)

6. [프로그래머스-파괴되지 않은 건물](https://school.programmers.co.kr/learn/courses/30/lessons/92344)

## 참고

- [블로그 참조 -(musclecode: 누적합(Prefix Sum / Cumulative Sum) 알고리즘)](https://ji-musclecode.tistory.com/38)

- [블로그 참조 - (jow1025: 누적합(prefix sum)](https://jow1025.tistory.com/47)

- [블로그 참조 - PrefixSum +1-1 기법 또는 차분 배열 기법(Difference Array Technique)](https://jypark1111.tistory.com/201)

- [블로그 참조 - PrefixSum +1-1 기법 또는 차분 배열](https://velog.io/@hyunsoo730/PrefixSum-1-1-%EA%B8%B0%EB%B2%95-%EB%98%90%EB%8A%94-%EC%B0%A8%EB%B6%84-%EB%B0%B0%EC%97%B4)

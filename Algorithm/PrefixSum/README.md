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

## 연습문제

0. [BOJ-11659(구간 합 구하기 4)](https://www.acmicpc.net/problem/11659) , [BOJ-11660(구간 합 구하기 5)](https://www.acmicpc.net/problem/11660)

1. [BOJ-29700(우당탕탕 영화예매)](https://www.acmicpc.net/problem/29700)

2. [BOJ-20438(출석체크)](https://www.acmicpc.net/problem/20438)

3. [BOJ-21318(피아노 체조)](https://www.acmicpc.net/problem/21318)

4. [BOJ-16507(어두운 건 무서워)](https://www.acmicpc.net/problem/16507)

5. [BOJ-19951(태상이의 훈련소 생활)](https://www.acmicpc.net/problem/19951)

6. [프로그래머스-파괴되지 않은 건물](https://school.programmers.co.kr/learn/courses/30/lessons/92344)

## 참고

- [블로그-참조(musclecode: 누적합(Prefix Sum / Cumulative Sum) 알고리즘)](https://ji-musclecode.tistory.com/38)

- [블로그-참조(jow1025: 누적합(prefix sum)](https://jow1025.tistory.com/47)

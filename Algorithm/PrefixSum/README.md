# Prefix Sum / Cumulative Sum

> 배열의 일부 구간 합을 빠르게 계산하기 위한 기법

## 1차원 누적합 (Prefix Sum)

> 구간 합을 **O(1)** 에 구하기 위한 핵심 기법

**구간합** : `sum(l...r) = prefix[r] - prefix[l-1]`

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

  ---

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

---

## 2차원 누적합 (2D Prefix Sum)

> 영역 합 문제(예: 부분 행렬 합)에서 자주 등장

**점화식** : `prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + arr[i][j]`

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

  ---

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

---

## 차분 배열 기법(Difference Array Technique)

> 주로 누적합과 함께 사용되며, 배열의 연속적인 부분에 대한 업데이트를 빠르게 수행할 수 있도록 해준다

누적합의 역개념으로 구간에 `+1`, `-1` 같은 업데이트를 효율적으로 하는 방식

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

     ---

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
             prefixSum[i][j+1] += prefixSum[i][j]
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
             prefixSum[i+1][j] += prefixSum[i][j]
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

---

## [EX01)BOJ 11659 - 구간 합 구하기 4](https://www.acmicpc.net/problem/11659)

<details markdown="1">
<summary>info</summary>

### 문제

수 `N`개가 주어졌을 때, `i`번째 수부터 `j`번째 수까지 합을 구하는 프로그램을 작성하시오.

### 입력

첫째 줄에 수의 개수 `N`과 합을 구해야 하는 횟수 `M`이 주어진다.

둘째 줄에는 `N`개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다.

셋째 줄부터 `M`개의 줄에는 합을 구해야 하는 구간 `i`와 `j`가 주어진다.

### 출력

총 `M`개의 줄에 입력으로 주어진 `i`번째 수부터 `j`번째 수까지 합을 출력한다.

### 제한

- 1 ≤ `N` ≤ 100,000

- 1 ≤ `M` ≤ 100,000

- 1 ≤ `i` ≤ `j` ≤ `N`


### 입출력

- 01

    ```
    5 3
    5 4 3 2 1
    1 3
    2 4
    5 5
    ```

    ```
    12
    9
    1
    ```

</details>

<details markdown="1">
<summary>code</summary>

```cpp
#include<iostream>
#include<vector>

using namespace std;

void solution(int N, int M, vector<int> seq, vector<vector<int>> pos) {
    vector<int> prefixSum(N+1, 0);

    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + seq[i];
    }

    for (vector<int> p: pos) {

        cout << prefixSum[p[1]] - prefixSum[p[0]-1] << '\n';
    }
    return;
}

int main(void) {
    int N, M, s, e;
    vector<int> seq;
    vector<vector<int>> pos;

    cin >> N >> M;
    seq = vector<int>(N, 0);
    pos = vector<vector<int>>(M, vector<int>(2, 0));
    
    for (int &s: seq) {
        cin >> s;
    }

    for (vector<int> &p: pos) {
        cin >> p[0] >> p[1];
    }

    solution(N, M, seq, pos);
    
    return 0;
}
```

```swift
let NM = readLine()!.split(separator: " ").map{Int(String($0))!}
let arr = readLine()!.split(separator: " ").map{Int(String($0))!}

var prefixSum = Array(repeating: 0, count: NM[0] + 1)

for i in 0..<NM[0] {
    prefixSum[i + 1] = arr[i] + prefixSum[i]
}

for _ in 0..<NM[1] {
    let se = readLine()!.split(separator: " ").map{Int(String($0))!}
    print(prefixSum[se[1]] - prefixSum[se[0]-1])
}
```

</details>

---

## [EX02) BOJ 11660 - 구간 합 구하기 5](https://www.acmicpc.net/problem/11660)

<details markdown="1">
<summary>info</summary>

### 문제

N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.

예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.

```
1	2	3	4
2	3	4	5
3	4	5	6
4	5	6	7
```

여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.

표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.

### 입력

첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000)

둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다.

다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

### 출력

총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.

### 제한

- 1 ≤ `N` ≤ 100,000

- 1 ≤ `M` ≤ 100,000

- 1 ≤ `i` ≤ `j` ≤ `N`


### 입출력

- 01

    ```
    4 3
    1 2 3 4
    2 3 4 5
    3 4 5 6
    4 5 6 7
    2 2 3 4
    3 4 3 4
    1 1 4 4
    ```

    ```
    27
    6
    64
    ```

    ---

- 02

    ```
    2 4
    1 2
    3 4
    1 1 1 1
    1 2 1 2
    2 1 2 1
    2 2 2 2
    ```

    ```
    1
    2
    3
    4
    ```

</details>

<details markdown="1">
<summary>code</summary>

```cpp
#include<iostream>
#include<vector>

using namespace std;

void solution(int N, int M,  vector<vector<int>> arr, vector<vector<int>> cmd) {
    vector<vector<int>> prefixSum(N+1, vector<int>(N+1, 0));
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {  
            prefixSum[i][j] = arr[i-1][j-1] + (prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i-1][j-1]);
        }
    }

    for (vector<int> c: cmd) {
        int x1 = c[0], y1 = c[1], x2 = c[2], y2 = c[3];
        int val = prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1];

        cout << val << '\n';
    }
    return;
}

int main(void) {
    int N, M;
    vector<vector<int>> arr;
    vector<vector<int>> cmd;

    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(N, 0));
    cmd = vector<vector<int>>(M, vector<int>(4, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2] >> cmd[i][3];
    }

    solution(N, M, arr, cmd);
    return 0;
}
```

```swift
let NM = readLine()!.split(separator: " ").map{ Int($0)! }
var arr: [[Int]] = []

for _ in 0..<NM[0] {
    arr.append(readLine()!.split(separator: " ").map{ Int($0)! })
}

var prefixSum = Array(repeating: Array(repeating: 0, count: NM[0] + 1), count: NM[0] + 1)

for i in 1...NM[0] {
    for j in 1...NM[0] {
        prefixSum[i][j] = arr[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1]
    }
}

for _ in 0..<NM[1] {
    let pos = readLine()!.split(separator: " ").map{ Int($0)! }
    let x1 = pos[0], y1 = pos[1], x2 = pos[2], y2 = pos[3]

    print(prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1])
}
```

</details>

---

## 문제 List

### 정형화

- [BOJ 29700 - 우당탕탕 영화예매](https://www.acmicpc.net/problem/29700)


- [BOJ 21318 - 피아노 체조](https://www.acmicpc.net/problem/21318)

- [Leetcode - Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/description/)

---

### 응용


- [BOJ 16139 - 인간-컴퓨터 상호작용](https://www.acmicpc.net/problem/16139)

- [BOJ 16507 - 어두운 건 무서워](https://www.acmicpc.net/problem/16507)

- [BOJ 19951 - 태상이의 훈련소 생활](https://www.acmicpc.net/problem/19951)

### 실전

- [BOJ 20438 - 출석체크](https://www.acmicpc.net/problem/20438)

- [Programmers - 광고 삽입](https://school.programmers.co.kr/learn/courses/30/lessons/72414)

- [Programmers - 파괴되지 않은 건물](https://school.programmers.co.kr/learn/courses/30/lessons/92344)

---

## 참고

- [블로그 참조 -(musclecode: 누적합(Prefix Sum / Cumulative Sum) 알고리즘)](https://ji-musclecode.tistory.com/38)

- [블로그 참조 - (jow1025: 누적합(prefix sum)](https://jow1025.tistory.com/47)

- [블로그 참조 - PrefixSum +1-1 기법 또는 차분 배열 기법(Difference Array Technique)](https://jypark1111.tistory.com/201)

- [블로그 참조 - PrefixSum +1-1 기법 또는 차분 배열](https://velog.io/@hyunsoo730/PrefixSum-1-1-%EA%B8%B0%EB%B2%95-%EB%98%90%EB%8A%94-%EC%B0%A8%EB%B6%84-%EB%B0%B0%EC%97%B4)

- [블로그 참조 - 백준 16139 인간-컴퓨터 상호작용 (Swift)(만도스의 개발 일기장)](https://dev-mandos.tistory.com/224)
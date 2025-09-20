# Two Pointer / Sliding Window

- **Two Pointer**

  > 배열에 순차적으로 접근해야 할 때 두 개의 점의 위치를 기록하면서 처리하는 알고리즘

  - 포인터 2개를 사용해서 탐색 범위를 좁혀가는 방식

  - 정렬된 배열에서 특정 조건을 만족하는 구간을 찾을 때 많이 사용

  - 시간 복잡도: `O(N)` or `O(NlogN)`

---

- **Sliding Window**

  > 고정된 크기 또는 가변 크기의 윈도우를 사용하여 탐색하는 알고리즘

  - 배열이나 문자열에서 특정 크기의 부분을 확인하며 이동하는 방식

  - **연속된 부분 배열(구간)**을 빠르게 탐색할 때, _최대/최소 합_ , _평균_ , _부분 문자열_ 문제에 자주 사용

  - 시간 복잡도: `O(N)`

---

## [Ex01) BOJ 2003 - 수들의 합 2](https://www.acmicpc.net/problem/2003)

<details markdown="1">
<summary>info</summary>

### 문제

`N`개의 수로 된 수열 `A[1], A[2], …, A[N]` 이 있다. 이 수열의 `i`번째 수부터 `j`번째 수까지의 합 `A[i] + A[i+1] + … + A[j-1] + A[j]`가 `M`이 되는 경우의 수를 구하는 프로그램을 작성하시오.

### 입력

첫째 줄에 `N(1 ≤ N ≤ 10,000)`, `M(1 ≤ M ≤ 300,000,000)`이 주어진다. 다음 줄에는 `A[1], A[2], …, A[N]`이 공백으로 분리되어 주어진다. 각각의 `A[x]`는 `30,000`을 넘지 않는 자연수이다.

### 출력

첫째 줄에 경우의 수를 출력한다.

### 입출력

- 01

    ```
    4 2
    1 1 1 1
    ```

    ```
    3
    ```

- 02

    ```
    10 5
    1 2 3 4 2 5 3 1 1 2
    ```

    ```
    3
    ```

</details>

1. 모든 구간 `[i, j]`를 잡고 합을 구해야 함

2. 시간복잡도: `O(N²)` -> `N` = 10만 이면 시간 초과

3. 두 개의 포인터(`l` , `r`)와 현재 `sum` 을 관리

    - `sum < M` -> `r` 를 오른쪽으로 이동, `sum += A[r]`

    - `sum >= M` -> `l`를 오른쪽으로 이동, `sum -= A[l]`

    - 만약 `sum == M` 이면 경우의 수 +1

    - `r`이 배열 끝에 도달할 때까지 반복

<details markdown="1">
<summary>code</summary>

```cpp
#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    int N, M;
    vector<int> seq;

    cin >> N >> M;
    seq = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> seq[i];

    long long answer = 0;
    int s = 0, e = 0, partial_sum = 0;

    while (s <= e && e <= N) {
        if (M == partial_sum) answer++;

        if (M <= partial_sum) {
            partial_sum -= seq[s++];
        }
        else if (M > partial_sum) {
            partial_sum += seq[e++];
        }
    }

    cout << answer << '\n';
    return 0;
}
```

```swift
import Foundation

let NM = readLine()!.split(separator: " ").map{ Int(String($0))! }
let arr: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }

print(solution(NM[0], NM[1], arr))

func solution(_ N: Int, _ M: Int, _ arr: [Int]) -> Int {
  var answer: Int = 0
  var l: Int = 0, r: Int = 0, sum: Int = arr[0]
  
  while r < arr.count {
    if sum == M {
      answer += 1
    }

    if sum > M {
      sum -= arr[l]
      l += 1
      
    } else {
      r += 1
      sum += r == arr.count ? 0 : arr[r]
    }
  }
  
  return answer
} // solution
```

</details>

---

## [Ex02) BOJ 21921 - 블로그](https://www.acmicpc.net/problem/21921)

<details markdown="1">
<summary>info</summary>

### 문제

찬솔이는 블로그를 시작한 지 벌써 `N`일이 지났다.

요즘 바빠서 관리를 못 했다가 방문 기록을 봤더니 벌써 누적 방문 수가 6만을 넘었다.

찬솔이는 `X`일 동안 가장 많이 들어온 방문자 수와 그 기간들을 알고 싶다.

찬솔이를 대신해서 `X`일 동안 가장 많이 들어온 방문자 수와 기간이 몇 개 있는지 구해주자.

### 입력

첫째 줄에 블로그를 시작하고 지난 일수 `N`와 `X`가 공백으로 구분되어 주어진다.

둘째 줄에는 블로그 시작 `1`일차부터 `N`일차까지 하루 방문자 수가 공백으로 구분되어 주어진다.

- `1` <= `X` <= `N` <= `250000`

- `0` <= 방문자 수 <= `8000`

### 출력

첫째 줄에 `X`일 동안 가장 많이 들어온 방문자 수를 출력한다. 만약 최대 방문자 수가 `0`명이라면 `SAD`를 출력한다.

만약 최대 방문자 수가 0명이 아닌 경우 둘째 줄에 기간이 몇 개 있는지 출력한다.

### 예제 입출력

- 01

    ```
    5 2
    1 4 2 5 1
    ```

    ```
    7
    1
    ```

- 02

    ```
    7 5
    1 1 1 1 1 5 1
    ```

    ```
    9
    2
    ```

- 03

    ```
    5 3
    0 0 0 0 0
    ```

    ```
    SAD
    ```

</details>

<details markdown="1">
<summary>code</summary>

```swift
import Foundation

let NX = readLine()!.split(separator: " ").map{ Int(String($0))! }
let visitors: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }

print(solution(NX[0], NX[1], visitors))

func solution(_ N: Int, _ X: Int, _ visitors: [Int]) -> String {
  var answer: Int = 0
  var cnt: Int = 0
  var prefixSum = [Int](repeating: 0, count: N + 1)

  for i in 1...N {
    prefixSum[i] = prefixSum[i - 1] + visitors[i - 1]
  }

  for i in 0...(N - X) {
    let sum = prefixSum[i + X] - prefixSum[i]
    
    if answer < sum {
      answer = sum
      cnt = 1
    } else if answer == sum {
      cnt += 1
    }
  }
  
  return answer == 0 ? "SAD" : "\(answer)\n\(cnt)"
} // solution

```

</details>

---

## 자주 사용되는 패턴

- "배열이 정렬되어 있고, 두 개의 원소를 비교해야 한다?" -> **Two Pointer**

- "연속된 부분 배열(구간)의 값을 빠르게 구해야 한다?" -> **Sliding Window**

---

### 합이 특정 값인 두 수 찾기

```swift
func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var left = 0
    var right = nums.count - 1

    while left < right {
        let sum = nums[left] + nums[right]

        if sum == target {
            return [left, right]
        } else if sum < target {
            left += 1
        } else {
            right -= 1
        }
    }

    return []
}

print(twoSum([2, 7, 11, 15], 9))
// [0, 1]
```

- 정렬된 배열에서 **왼쪽에서 시작하는 포인터(`left`)** 와 **오른쪽에서 시작하는 포인터(`right`)** 를 이동하면서 구간의 합을 조정

- 시간복잡도: `O(N)`

---

### 부분 합 문제 (Subarray Sum)

- 윈도우 크기만큼 부분 배열을 확인하고, 윈도우를 한 칸씩 이동하면서 값을 갱신

- 이전 값을 활용하여 중복 연산을 피함

---

#### 연속된 부분 배열의 합이 K 이상이 되는 최소 구간(= 길이)

```swift
func subArrayMinLength(_ nums: [Int], _ target: Int) -> Int {
    var res: Int = Int.max
    var left = 0, sum = 0

    for right in 0..<nums.count {
        sum += nums[right]

        while sum >= target {
            res = min(res, right - left + 1)
            sum -= nums[left]
            left += 1
        }
    }

    if res == Int.max {
        res = 0
    }

    return res
}

print(subArrayMinLength([2, 3, 1, 2, 4, 3], 7))
// 2 ([4,3])
```

1.  `right` 를 오른쪽으로 이동하면서 부분 합을 구함

2.  조건을 만족하면 `left` 를 이동하여 최소 길이를 찾음

---

#### 길이 K인 부분 배열의 최대 합 찾기

```swift
func subArrayMaxSum(_ nums: [Int], _ length: Int) -> Int {
    var res: Int = -1
    var tot = nums[0..<length].reduce(0, +)
    res = tot

    for i in length..<nums.count {
        tot += nums[i] - nums[i - length] // 새로운 값 추가, 이전 값 제거
        res = res > tot ? res : tot
    }

    return res
}

```

1. 매번 전체 합을 구하는 대신

2. 앞의 값만 빼고 뒤의 값을 추가함

---

## 문제 List

### 정형화

- [BOJ 2559 - 수열 (슬라이딩 윈도우)](https://www.acmicpc.net/problem/2559)

- [Programmers - 보석 쇼핑 (투 포인터)](https://school.programmers.co.kr/learn/courses/30/lessons/67258)

- [Leetcode - Minimum Size Subarray Sum (슬라이딩 윈도우)](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

- [Leetcode - Longest Substring Without Repeating Characters (슬라이딩 윈도우)](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---

### 응용

- [BOJ 2531 - 회전 초밥](https://www.acmicpc.net/problem/2531)

- [BOJ 1806 - 부분합](https://www.acmicpc.net/problem/1806)

- [BOJ 1644 - 소수의 연속합](https://www.acmicpc.net/problem/1644)

- [Programmers - 연속 부분 수열 합의 개수](https://school.programmers.co.kr/learn/courses/30/lessons/131701)

- [Leetcode - Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

---

### 실전

- [BOJ 2467 – 용액](https://www.acmicpc.net/problem/2467)

- [BOJ 2470 – 두 용액](https://www.acmicpc.net/problem/2470)

- [LeetCode - Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

---